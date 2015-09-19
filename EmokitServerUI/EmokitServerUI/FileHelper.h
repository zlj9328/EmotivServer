#ifndef FILEHELPER_H
#define FILEHELPER_H

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;

#define EMOKIT_CHANNEL_DATA "Emokit_Channel_Data"
#define HEART_RATE_DATA     "Heart_Rate_Data"
#define WARNING_DATA		"Waring_Data.txt"

void FileWriteSystemTime(string name);
void FileWriteString(string name, const char *str, int len);
void FileWriteInt(string name, int dat);
std::string Name(std::string name, int num);

/*文件操作函数，注：Emokit通道数据包和心电数据包是每个用户各一个txt文件，警告包为一个*/
void FileWriteChannelData(string filename, const char *channel1, int dat1, const char *channel2, int dat2);
void FileWriteHeartRateData(string filename, int BMP, int Signal, int IBI);
void FileWriteWarningData(string filename, int key, int warning);

#endif