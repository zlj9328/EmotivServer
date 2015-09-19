#ifndef UDPSOCKET_H
#define UDPSOCKET_H

#include <winsock.h>
#include <string>

/*���ݰ�����ID*/
#define PKT_CHANNEL		1001
#define PKT_HEART_RATE	1002
#define PKT_WARNING		1003
#define PKT_LOGIN		1004
#define PKT_LOGOUT      1005
#define PKT_ACK         1006

/*���ݰ�����*/
typedef struct PktHeader
{
	int nPktType;
}PktHeader;

/*�豸Key*/
typedef struct PktKey
{
	int nKey;
}PktKey;

/*������Ϣ��*/
typedef struct PktWarning
{
	PktHeader header;
	PktKey keyNumber;
	int warningMsg;
}PktWarning;

/*ͨ�����ݰ�*/
typedef struct PktChannelData
{
	PktHeader header;
	PktKey keyNumber;

	char channelType1[4];
	int channelData1;
	char channelType2[4];
	int channelData2;
}PktChannelData;

/*�ĵ����ݰ�*/
typedef struct PktHeartRate
{
	PktHeader header;
	PktKey keyNumber;

	int BMP;
	int Signal;
	int IBI;
}PktHeartRate;

/*�����*/
typedef struct PktLogin
{
	PktHeader header;
	PktKey keyNumber;
}PktLogin;

/*�ǳ���*/
typedef struct PktLogOut
{
	PktHeader header;
	PktKey keyNumber;
}PktLogOut;

/*ack��*/
typedef struct PktAck
{
	PktHeader header;
	PktKey keyNumber;
}PktAck;

/*UDP��*/
class UDPHelper
{
public:
	std::string m_IP;
	int m_Port;

	WSADATA wsaData;
	SOCKET sockListen;
	sockaddr_in saLocal;
	sockaddr_in saFrom;
	int nFromLen;
public:
	UDPHelper(std::string IP, int Port);
	UDPHelper(int Port);
	~UDPHelper();

	void InitUDPSocket();
	void Unbind();
	int UDPSend(const char *data, int length);
	int UDPRecv(char *data, int length);
};

void ProcessPkt(const char *data);

#endif