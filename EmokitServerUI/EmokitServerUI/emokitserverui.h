#ifndef EMOKITSERVERUI_H
#define EMOKITSERVERUI_H

#include <QtWidgets/QMainWindow>
#include "ui_emokitserverui.h"
#include <QStringListModel>
#include "Thread.h"
#include <QSettings>

/*QT中文显示优化*/
#if _MSC_VER >= 1600  
#pragma execution_character_set("utf-8")  
#endif  

class EmokitServerUI : public QMainWindow
{
	Q_OBJECT

public:
	EmokitServerUI(QWidget *parent = 0);
	~EmokitServerUI();
	int UserListViewSelect();

private:
	Ui::EmokitServerUIClass ui;

	QAction *Setting;
	QAction *Graph;
	QAction *File;
	RecvThread *recvThread;

	QStringList userList;
	QStringListModel *userListModel;

	QSettings *settingConfig;
	
	int TimeID;

private slots:
	/*菜单栏槽函数*/
	void setting_Dialog();
	void graph_Dialog();
	void file_Dialog();
	/*按键槽函数*/
	void start_Server();
	void stop_Server();
	void clear_Msg();

	void RecvDataSlot(int a, int type);
	void UserListViewInsert(int key);
	void UserListViewDelete(int key);

protected:
	void timerEvent(QTimerEvent *event);
};

#endif // EMOKITSERVERUI_H
