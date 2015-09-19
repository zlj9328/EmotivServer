#ifndef THREAD_H
#define THREAD_H

#include <QThread>

/*�����߳���*/
class RecvThread : public QThread
{
	Q_OBJECT
public:
	void run();
	void ProcessPkt(const char *data);
signals:
	void RecvDataSignal(int a, int type);//���ݽ����ź�
	void UpdateDataSignal(int channel1, int channel2);//����ͼͨ�����ݸ����ź�
	void LoginSignal(int key);//������Ϣ��
	void LogOutSignal(int key);//�ǳ��ź�
};



#endif