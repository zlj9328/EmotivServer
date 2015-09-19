#ifndef UDPSOCKET_H
#define UDPSOCKET_H

#include <winsock.h>
#include <string>

/*数据包类型ID*/
#define PKT_CHANNEL		1001
#define PKT_HEART_RATE	1002
#define PKT_WARNING		1003
#define PKT_LOGIN		1004
#define PKT_LOGOUT      1005
#define PKT_ACK         1006

/*数据包类型*/
typedef struct PktHeader
{
	int nPktType;
}PktHeader;

/*设备Key*/
typedef struct PktKey
{
	int nKey;
}PktKey;

/*警告信息包*/
typedef struct PktWarning
{
	PktHeader header;
	PktKey keyNumber;
	int warningMsg;
}PktWarning;

/*通道数据包*/
typedef struct PktChannelData
{
	PktHeader header;
	PktKey keyNumber;

	char channelType1[4];
	int channelData1;
	char channelType2[4];
	int channelData2;
}PktChannelData;

/*心电数据包*/
typedef struct PktHeartRate
{
	PktHeader header;
	PktKey keyNumber;

	int BMP;
	int Signal;
	int IBI;
}PktHeartRate;

/*登入包*/
typedef struct PktLogin
{
	PktHeader header;
	PktKey keyNumber;
}PktLogin;

/*登出包*/
typedef struct PktLogOut
{
	PktHeader header;
	PktKey keyNumber;
}PktLogOut;

/*ack包*/
typedef struct PktAck
{
	PktHeader header;
	PktKey keyNumber;
}PktAck;

/*UDP类*/
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