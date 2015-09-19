#include "GlobalVar.h"

/*全局变量*/
UDPHelper udpHelper(DEFAULT_PORT);
//int key_Number = 0;//记录当前收到的是哪个用户的数据
int graph_key = -1;//记录当前显示的是哪个用户的折线图
QStringList UserListAck;//记录返回ack包的用户

int server_state = SERVER_STATE_STOP;