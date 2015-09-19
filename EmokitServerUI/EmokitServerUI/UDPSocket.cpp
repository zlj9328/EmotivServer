#include "UDPSocket.h"
#include <QDebug>
#include "FileHelper.h"
#include "GlobalVar.h"
#pragma comment(lib, "ws2_32.lib")


/*���캯��*/
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
/*���캯��*/
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

/*��������*/
UDPHelper::~UDPHelper()
{
	closesocket(sockListen);
	WSACleanup();
}

/*UDP��ʼ������*/
void UDPHelper::InitUDPSocket()
{
	sockListen = socket(AF_INET, SOCK_DGRAM, 0);
	if (sockListen == INVALID_SOCKET)
	{
		qFatal("����socket����");
		return;
	}

	sockaddr_in saLocal;
	memset(&saLocal, 0, sizeof(saLocal));
	saLocal.sin_family = AF_INET; //Address family
	saLocal.sin_addr.s_addr = INADDR_ANY; //Wild card IP address
	saLocal.sin_port = htons((u_short)m_Port); //port to use

	if (bind(sockListen, (struct sockaddr *)&saLocal, sizeof(saLocal)) != 0)
	{
		qFatal("bind����");
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
*���ͺ���
*data�����͵����ݣ�length�����ݳ���
*return�����͵����ݺ���
*/
int UDPHelper::UDPSend(const char *data, int length)
{
	return sendto(sockListen, data, length + 1, 0, (sockaddr *)&saFrom, sizeof(saFrom));
}

/*
*���պ���
*data���������ݻ�������length������������
*return�����ؽ������ݳ���
*/
int UDPHelper::UDPRecv(char *data, int length)
{
	memset(&saFrom, 0, sizeof(saFrom));
	nFromLen = sizeof(saFrom);
	return recvfrom(sockListen, data, length, 0, (sockaddr *)&saFrom, &nFromLen);
}



