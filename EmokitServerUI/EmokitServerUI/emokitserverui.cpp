#include "emokitserverui.h"
#include "SettingDialog.h"
#include "GraphDialog.h"
#include "GlobalVar.h"

/*构造函数*/
EmokitServerUI::EmokitServerUI(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	TimeID = startTimer(15000);

	/*菜单栏初始化*/
	File = new QAction(tr("文件"), this);
	File->setStatusTip(tr("打开文件"));
	ui.mainToolBar->addAction(File);
	connect(File, SIGNAL(triggered()), this, SLOT(file_Dialog()));

	Graph = new QAction(tr("图表"), this);
	Graph->setStatusTip(tr("显示折线图"));
	ui.mainToolBar->addAction(Graph);
	connect(Graph, SIGNAL(triggered()), this, SLOT(graph_Dialog()));

	Setting = new QAction(tr("设置"), this);
	Setting->setStatusTip(tr("设置"));
	ui.mainToolBar->addAction(Setting);
	connect(Setting, SIGNAL(triggered()), this, SLOT(setting_Dialog()));

	/*button初始化*/
	ui.StartServer->setStatusTip(tr("启动服务器"));
	connect(ui.StartServer, SIGNAL(clicked()), this, SLOT(start_Server()));

	ui.StopServer->setStatusTip(tr("停止服务器"));
	connect(ui.StopServer, SIGNAL(clicked()), this, SLOT(stop_Server()));
	
	ui.StartServer->setEnabled(true);
	ui.StopServer->setEnabled(false);

	ui.ClearMsgButton->setStatusTip(tr("清除消息框内容"));
	connect(ui.ClearMsgButton, SIGNAL(clicked()), this, SLOT(clear_Msg()));

	/*接收数据线程初始化*/
	recvThread = new RecvThread;
	connect(recvThread, SIGNAL(RecvDataSignal(int,int)), this, SLOT(RecvDataSlot(int,int)));

	/*在线用户列表初始化*/
	userListModel = new QStringListModel(userList);
	ui.UserListView->setModel(userListModel);
	ui.UserListView->setEditTriggers(QAbstractItemView::NoEditTriggers);

	/*登入登出信号连接*/
	connect(recvThread, SIGNAL(LoginSignal(int)), this, SLOT(UserListViewInsert(int)));
	connect(recvThread, SIGNAL(LogOutSignal(int)), this, SLOT(UserListViewDelete(int)));

	settingConfig = new QSettings("EmokitServerConfig.ini");
	udpHelper.m_IP = settingConfig->value(IP_POINT).toString().toStdString();
	udpHelper.m_Port = settingConfig->value(PORT_POINT).toInt();
	udpHelper.InitUDPSocket();
	delete settingConfig;

	qDebug("Start Server UI");

}

/*析构函数*/
EmokitServerUI::~EmokitServerUI()
{
	qDebug("Stop Server UI");
	if (!recvThread->isFinished())
	{
		recvThread->terminate();
		recvThread->wait();
	}
	
	delete Setting;
	delete Graph;
	delete recvThread;
	delete userListModel;
}

/*设置界面槽函数*/
void EmokitServerUI::setting_Dialog()
{
	qDebug("Start Setting Dialog");
	SettingDialog settingDialog(this);
	settingDialog.setFixedSize(400,300);
	settingDialog.setWindowTitle("设置");
	settingDialog.exec();
}

/*折线图界面槽函数*/
void EmokitServerUI::graph_Dialog()
{
	qDebug("Start Graph Dialog");
	GraphDialog graphDialog(this);
	graphDialog.setFixedSize(637, 371);

	graph_key = UserListViewSelect();//获取选中的用户，未选中返回-1
	if (graph_key > 0)
	{
		/*Title设置*/
		QString str = "折线图  用户:";
		str.append(QString::number(graph_key));
		graphDialog.setWindowTitle(str);
		/*连接数据更新信号槽*/
		connect(recvThread, SIGNAL(UpdateDataSignal(int, int)), &graphDialog, SLOT(GraphUpdateData(int, int)));
	}
	else
	{
		QString str = "折线图  未选择用户";
		graphDialog.setWindowTitle(str);
	}
	graphDialog.exec();
}

/*打开文件夹*/
void EmokitServerUI::file_Dialog()
{
	QString path = QDir::currentPath();//获取程序当前目录  
	path.replace("/", "\\");
	QProcess::startDetached("explorer " + path);//打开上面获取的目录  
}


/*启动服务槽函数*/
void EmokitServerUI::start_Server()
{
	qDebug("Start Server");
	ui.ShowInfo->append("服务器启动");
	recvThread->start();

	ui.StartServer->setEnabled(false);
	ui.StopServer->setEnabled(true);
	server_state = SERVER_STATE_START;
}

/*停止服务槽函数*/
void EmokitServerUI::stop_Server()
{
	ui.StartServer->setEnabled(true);
	ui.StopServer->setEnabled(false);
	/*停止线程*/
	recvThread->terminate();
	recvThread->wait();
	qDebug("Stop Server");
	ui.ShowInfo->append("服务器停止");
	server_state = SERVER_STATE_STOP;
}

void EmokitServerUI::clear_Msg()
{
	ui.ShowInfo->clear();
}

/*
*接收数据槽函数
*a：为用户的key
*/
void EmokitServerUI::RecvDataSlot(int a,int type)
{
	QString str = "接收来自";
	str.append(QString::number(a));
	str.append("的信息:");

	switch (type)
	{
		case PKT_ACK:		str.append("Ack");		break;
		case PKT_LOGIN:		str.append("Login");	break;
		case PKT_LOGOUT:	str.append("LogOut");	break;
		case PKT_WARNING:	str.append("Warning");	break;
		default:break;
	}
	ui.ShowInfo->append(str);
}

/*
*插入用户列表槽函数
*key：用户的key
*/
void EmokitServerUI::UserListViewInsert(int key)
{
	QString str = "用户:";
	str.append(QString::number(key));

	if (userList.indexOf(str) < 0)//用户不存在时才插入，避免重复插入
	{
		userList += str;
		userList.sort();
		userListModel->setStringList(userList);
	}
}

/*
*删除用户列表槽函数
**key：用户的key
*/
void EmokitServerUI::UserListViewDelete(int key)
{
	int id;
	QString str = "用户:";
	str.append(QString::number(key));
	id = userList.indexOf(str);//查找用户存在时，才可以删除

	if (id >=0 && userListModel->rowCount() > 0) 
	{
		userListModel->removeRows(id, 1);
	}
	UserListAck.removeAt(id);
}

/*
*选择用户
*return：选择的用户的key;
*/
int EmokitServerUI::UserListViewSelect()
{
	int key = -1;
	if (userList.length() > 0)
	{
		int row;
		row = ui.UserListView->currentIndex().row();
		QModelIndex index = userListModel->index(row);
		QVariant variant = userListModel->data(index, Qt::DisplayRole);  //获取当前选择的项的文本
		QString info = variant.toString();
		QString number = info.split(":").last();
		key = number.toInt();
	}
	return key;
}

/*定时器中断服务函数*/
void EmokitServerUI::timerEvent(QTimerEvent *event)
{
	if (event->timerId() == TimeID)
	{
		userList.clear();
		QList<QString>::iterator i;
		/*将返回ack信息的用户放在userList*/
		for (i = UserListAck.begin(); i != UserListAck.end(); ++i) 
		{
			QString str = "用户:";
			*i = (*i).toLower();
			str.append(*i);
	//		if (userList.indexOf(*i) < 0)
			userList += str;
		}
		userList.sort();
		userListModel->setStringList(userList);
		UserListAck.clear();
	}
}
