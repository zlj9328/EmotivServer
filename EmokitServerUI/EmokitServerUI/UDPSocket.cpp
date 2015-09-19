#include "UDPSocket.h"
#include <QDebug>
#include "FileHelper.h"
#include "GlobalVar.h"
#pragma comment(lib, "ws2_32.lib")


/*构造函数*/
UDPHelper::UDPHelper(std::string IP, int Port)
{
	m_IP = IP;
	m_Port = Port;

	int nRet = WSAStartup(0x101, &wsaData);
	if (nRet != 0)
	{
		qFatal("WSAStartup error!!");
	}
//	InitUDPSocket();
}
/*构造函数*/
UDPHelper::UDPHelper(int Port)
{
	m_Port = Port;

	int nRet = WSAStartup(0x101, &wsaData);
	if (nRet != 0)
	{
		qFatal("WSAStartup error!!");
	}
//	InitUDPSocket();
}

/*析构函数*/
UDPHelper::~UDPHelper()
{
	closesocket(sockListen);
	WSACleanup();
}

/*UDP初始化函数*/
void UDPHelper::InitUDPSocket()
{
	sockListen = socket(AF_INET, SOCK_DGRAM, 0);
	if (sockListen == INVALID_SOCKET)
	{
		qFatal("创建socket出错");
		return;
	}

	sockaddr_in saLocal;
	memset(&saLocal, 0, sizeof(saLocal));
	saLocal.sin_family = AF_INET; //Address family
	saLocal.sin_addr.s_addr = INADDR_ANY; //Wild card IP address
	saLocal.sin_port = htons((u_short)m_Port); //port to use

	if (bind(sockListen, (struct sockaddr *)&saLocal, sizeof(saLocal)) != 0)
	{
		qFatal("bind出错");
		closesocket(sockListen);
		WSACleanup();
		return;
	}
}

void UDPHelper::Unbind()
{
	closesocket(sockListen);
}

/*
*发送函数
*data：发送的数据，length：数据长度
*return：发送的数据函数
*/
int UDPHelper::UDPSend(const char *data, int length)
{
	return sendto(sockListen, data, length + 1, 0, (sockaddr *)&saFrom, sizeof(saFrom));
}

/*
*接收函数
*data：接收数据缓冲区，length：缓冲区长度
*return：返回接收数据长度
*/
int UDPHelper::UDPRecv(char *data, int length)
{
	memset(&saFrom, 0, sizeof(saFrom));
	nFromLen = sizeof(saFrom);
	return recvfrom(sockListen, data, length, 0, (sockaddr *)&saFrom, &nFromLen);
}



