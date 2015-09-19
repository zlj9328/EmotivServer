#ifndef THREAD_H
#define THREAD_H

#include <QThread>

/*接收线程类*/
class RecvThread : public QThread
{
	Q_OBJECT
public:
	void run();
	void ProcessPkt(const char *data);
signals:
	void RecvDataSignal(int a, int type);//数据接收信号
	void UpdateDataSignal(int channel1, int channel2);//折线图通道数据更新信号
	void LoginSignal(int key);//登入信息号
	void LogOutSignal(int key);//登出信号
};



#endif