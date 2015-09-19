#ifndef GLONALVAR_H
#define GLONALVAR_H

#include "UDPSocket.h"
#include <QStringList>

#define DEFAULT_PORT 8888

#define SERVER_STATE_START  1
#define SERVER_STATE_STOP   2

extern UDPHelper udpHelper;
//extern int key_Number;
extern int graph_key;
extern QStringList UserListAck;
extern int server_state;

#endif