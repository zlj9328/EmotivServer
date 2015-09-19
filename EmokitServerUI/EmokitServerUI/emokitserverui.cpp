#include "emokitserverui.h"
#include "SettingDialog.h"
#include "GraphDialog.h"
#include "GlobalVar.h"

/*���캯��*/
EmokitServerUI::EmokitServerUI(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	TimeID = startTimer(15000);

	/*�˵�����ʼ��*/
	File = new QAction(tr("�ļ�"), this);
	File->setStatusTip(tr("���ļ�"));
	ui.mainToolBar->addAction(File);
	connect(File, SIGNAL(triggered()), this, SLOT(file_Dialog()));

	Graph = new QAction(tr("ͼ��"), this);
	Graph->setStatusTip(tr("��ʾ����ͼ"));
	ui.mainToolBar->addAction(Graph);
	connect(Graph, SIGNAL(triggered()), this, SLOT(graph_Dialog()));

	Setting = new QAction(tr("����"), this);
	Setting->setStatusTip(tr("����"));
	ui.mainToolBar->addAction(Setting);
	connect(Setting, SIGNAL(triggered()), this, SLOT(setting_Dialog()));

	/*button��ʼ��*/
	ui.StartServer->setStatusTip(tr("����������"));
	connect(ui.StartServer, SIGNAL(clicked()), this, SLOT(start_Server()));

	ui.StopServer->setStatusTip(tr("ֹͣ������"));
	connect(ui.StopServer, SIGNAL(clicked()), this, SLOT(stop_Server()));
	
	ui.StartServer->setEnabled(true);
	ui.StopServer->setEnabled(false);

	ui.ClearMsgButton->setStatusTip(tr("�����Ϣ������"));
	connect(ui.ClearMsgButton, SIGNAL(clicked()), this, SLOT(clear_Msg()));

	/*���������̳߳�ʼ��*/
	recvThread = new RecvThread;
	connect(recvThread, SIGNAL(RecvDataSignal(int,int)), this, SLOT(RecvDataSlot(int,int)));

	/*�����û��б��ʼ��*/
	userListModel = new QStringListModel(userList);
	ui.UserListView->setModel(userListModel);
	ui.UserListView->setEditTriggers(QAbstractItemView::NoEditTriggers);

	/*����ǳ��ź�����*/
	connect(recvThread, SIGNAL(LoginSignal(int)), this, SLOT(UserListViewInsert(int)));
	connect(recvThread, SIGNAL(LogOutSignal(int)), this, SLOT(UserListViewDelete(int)));

	settingConfig = new QSettings("EmokitServerConfig.ini");
	udpHelper.m_IP = settingConfig->value(IP_POINT).toString().toStdString();
	udpHelper.m_Port = settingConfig->value(PORT_POINT).toInt();
	udpHelper.InitUDPSocket();
	delete settingConfig;

	qDebug("Start Server UI");

}

/*��������*/
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

/*���ý���ۺ���*/
void EmokitServerUI::setting_Dialog()
{
	qDebug("Start Setting Dialog");
	SettingDialog settingDialog(this);
	settingDialog.setFixedSize(400,300);
	settingDialog.setWindowTitle("����");
	settingDialog.exec();
}

/*����ͼ����ۺ���*/
void EmokitServerUI::graph_Dialog()
{
	qDebug("Start Graph Dialog");
	GraphDialog graphDialog(this);
	graphDialog.setFixedSize(637, 371);

	graph_key = UserListViewSelect();//��ȡѡ�е��û���δѡ�з���-1
	if (graph_key > 0)
	{
		/*Title����*/
		QString str = "����ͼ  �û�:";
		str.append(QString::number(graph_key));
		graphDialog.setWindowTitle(str);
		/*�������ݸ����źŲ�*/
		connect(recvThread, SIGNAL(UpdateDataSignal(int, int)), &graphDialog, SLOT(GraphUpdateData(int, int)));
	}
	else
	{
		QString str = "����ͼ  δѡ���û�";
		graphDialog.setWindowTitle(str);
	}
	graphDialog.exec();
}

/*���ļ���*/
void EmokitServerUI::file_Dialog()
{
	QString path = QDir::currentPath();//��ȡ����ǰĿ¼  
	path.replace("/", "\\");
	QProcess::startDetached("explorer " + path);//�������ȡ��Ŀ¼  
}


/*��������ۺ���*/
void EmokitServerUI::start_Server()
{
	qDebug("Start Server");
	ui.ShowInfo->append("����������");
	recvThread->start();

	ui.StartServer->setEnabled(false);
	ui.StopServer->setEnabled(true);
	server_state = SERVER_STATE_START;
}

/*ֹͣ����ۺ���*/
void EmokitServerUI::stop_Server()
{
	ui.StartServer->setEnabled(true);
	ui.StopServer->setEnabled(false);
	/*ֹͣ�߳�*/
	recvThread->terminate();
	recvThread->wait();
	qDebug("Stop Server");
	ui.ShowInfo->append("������ֹͣ");
	server_state = SERVER_STATE_STOP;
}

void EmokitServerUI::clear_Msg()
{
	ui.ShowInfo->clear();
}

/*
*�������ݲۺ���
*a��Ϊ�û���key
*/
void EmokitServerUI::RecvDataSlot(int a,int type)
{
	QString str = "��������";
	str.append(QString::number(a));
	str.append("����Ϣ:");

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
*�����û��б�ۺ���
*key���û���key
*/
void EmokitServerUI::UserListViewInsert(int key)
{
	QString str = "�û�:";
	str.append(QString::number(key));

	if (userList.indexOf(str) < 0)//�û�������ʱ�Ų��룬�����ظ�����
	{
		userList += str;
		userList.sort();
		userListModel->setStringList(userList);
	}
}

/*
*ɾ���û��б�ۺ���
**key���û���key
*/
void EmokitServerUI::UserListViewDelete(int key)
{
	int id;
	QString str = "�û�:";
	str.append(QString::number(key));
	id = userList.indexOf(str);//�����û�����ʱ���ſ���ɾ��

	if (id >=0 && userListModel->rowCount() > 0) 
	{
		userListModel->removeRows(id, 1);
	}
	UserListAck.removeAt(id);
}

/*
*ѡ���û�
*return��ѡ����û���key;
*/
int EmokitServerUI::UserListViewSelect()
{
	int key = -1;
	if (userList.length() > 0)
	{
		int row;
		row = ui.UserListView->currentIndex().row();
		QModelIndex index = userListModel->index(row);
		QVariant variant = userListModel->data(index, Qt::DisplayRole);  //��ȡ��ǰѡ�������ı�
		QString info = variant.toString();
		QString number = info.split(":").last();
		key = number.toInt();
	}
	return key;
}

/*��ʱ���жϷ�����*/
void EmokitServerUI::timerEvent(QTimerEvent *event)
{
	if (event->timerId() == TimeID)
	{
		userList.clear();
		QList<QString>::iterator i;
		/*������ack��Ϣ���û�����userList*/
		for (i = UserListAck.begin(); i != UserListAck.end(); ++i) 
		{
			QString str = "�û�:";
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
