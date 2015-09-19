#include "Thread.h"
#include "FileHelper.h"
#include "GlobalVar.h"

/*
*���ݰ�������
*data�����������
*/
void RecvThread::ProcessPkt(const char *data)
{
	int key_Number;
	PktHeader *pktHeader = (PktHeader *)data;

	if (pktHeader->nPktType == PKT_ACK)//Ack������
	{
		PktLogin *pktAck = (PktLogin *)data;
		key_Number = pktAck->keyNumber.nKey;

		if (UserListAck.indexOf(QString::number(pktAck->keyNumber.nKey)) < 0)//����ack�û�����acklist�вŲ���
		{
			UserListAck += QString::number(pktAck->keyNumber.nKey);
		}
		emit RecvDataSignal(key_Number, PKT_ACK);
	}
	else if (pktHeader->nPktType == PKT_LOGIN)//���������
	{
		PktLogin *pktLogin = (PktLogin *)data;
		key_Number = pktLogin->keyNumber.nKey;
		emit LoginSignal(pktLogin->keyNumber.nKey);

		if (UserListAck.indexOf(QString::number(pktLogin->keyNumber.nKey)) < 0)//����ack�û�����acklist�вŲ���
		{
			UserListAck += QString::number(pktLogin->keyNumber.nKey);
		}
		emit RecvDataSignal(key_Number, PKT_LOGIN);
	}
	else if (pktHeader->nPktType == PKT_LOGOUT)//�ǳ�������
	{
		PktLogOut *pktLogOut = (PktLogOut *)data;
		key_Number = pktLogOut->keyNumber.nKey;
		emit LogOutSignal(pktLogOut->keyNumber.nKey);
		emit RecvDataSignal(key_Number, PKT_LOGOUT);
	}
	else if (pktHeader->nPktType == PKT_CHANNEL)//Emokitͨ��������
	{
		std::string filename = EMOKIT_CHANNEL_DATA;

		PktChannelData *pktChannelData = (PktChannelData *)data;
		key_Number = pktChannelData->keyNumber.nKey;
		FileWriteChannelData(Name(filename, key_Number), pktChannelData->channelType1, pktChannelData->channelData1, pktChannelData->channelType2, pktChannelData->channelData2);
		
		if (graph_key > 0 && graph_key == key_Number)
		{
			emit UpdateDataSignal(pktChannelData->channelData1, pktChannelData->channelData2);
		}		
	}
	else if (pktHeader->nPktType == PKT_HEART_RATE)//�ĵ������
	{
		std::string filename = HEART_RATE_DATA;

		PktHeartRate *pktHeartRate = (PktHeartRate *)data;
		key_Number = pktHeartRate->keyNumber.nKey;
		FileWriteHeartRateData(Name(filename, key_Number), pktHeartRate->BMP, pktHeartRate->Signal, pktHeartRate->IBI);
	}
	else if (pktHeader->nPktType == PKT_WARNING)//���������
	{
		PktWarning *pktWarning = (PktWarning *)data;
		key_Number = pktWarning->keyNumber.nKey;
		FileWriteWarningData(WARNING_DATA, key_Number, pktWarning->warningMsg);
		emit RecvDataSignal(key_Number, PKT_WARNING);
	}
}

void RecvThread::run()
{
	char recvDatabuf[512];
	int recvDataLen = 0;
	qDebug("thread");
	while (true)
	{
		recvDataLen = udpHelper.UDPRecv(recvDatabuf, 512);
		ProcessPkt(recvDatabuf);
	}
}

