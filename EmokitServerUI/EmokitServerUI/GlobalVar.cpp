#include "GlobalVar.h"

/*ȫ�ֱ���*/
UDPHelper udpHelper(DEFAULT_PORT);
//int key_Number = 0;//��¼��ǰ�յ������ĸ��û�������
int graph_key = -1;//��¼��ǰ��ʾ�����ĸ��û�������ͼ
QStringList UserListAck;//��¼����ack�����û�

int server_state = SERVER_STATE_STOP;