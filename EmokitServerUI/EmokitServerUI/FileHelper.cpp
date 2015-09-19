#include"FileHelper.h"
#include <sstream>

/*
*将系统时间写入文件
*name:文件名
*/
void FileWriteSystemTime(string name)
{
	time_t timep;
	tm date_time;
	time(&timep);
	date_time = *localtime(&timep);//获取系统时间
	ofstream out(name, ios::app);//写数据

	out << '\t' << '\t' << '\t';

	out << "----";
	out << date_time.tm_year + 1900 << "-" << date_time.tm_mon + 1 << "-" << date_time.tm_mday << "|";//写时间到文本
	out << date_time.tm_hour << ":" << date_time.tm_min << ":" << date_time.tm_sec;
	out << "----";
	out << endl;
	out.close();
}

/*
*将char数据写入文件
*name:文件名，str:写入的数据，len:数据长度
*/
void FileWriteString(string name, const char *str, int len)
{
	ofstream out(name, ios::app);//写数据
	out.write(str, len);
	out << '\t';
	out.close();
}

/*
*将char数据写入文件
*name:文件名，int:写入的int型数据
*/
void FileWriteInt(string name, int dat)
{
	char buf[6];
	itoa(dat,buf,10);
	FileWriteString(name, buf, strlen(buf));
}

/*
*用于文件名的拼接
*return：文件名
*/
std::string Name(std::string name, int num)
{
	std::stringstream ss;
	std::string str;
	ss << num;
	ss >> str;
	name.append("_Key_");
	return name.append(str);
}

/*
*写入通道数据至文件
*channel1:通道名称，dat1:通道数据，channel2:通道名称，dat2:通道数据
*/
void FileWriteChannelData(string filename, const char *channel1, int dat1, const char *channel2, int dat2)
{
	filename.append(".txt");
	FileWriteString(filename, channel1, strlen(channel1));
	FileWriteInt(filename, dat1);
	FileWriteSystemTime(filename);

	FileWriteString(filename, channel2, strlen(channel2));
	FileWriteInt(filename, dat2);
	FileWriteSystemTime(filename);
}

/*
*将心电数据写入文件
*BMP:Signal:IBI:
*/
void FileWriteHeartRateData(string filename, int BMP, int Signal, int IBI)
{
	filename.append(".txt");
	FileWriteString(filename, "BMP", 4);
	FileWriteInt(filename, BMP);
	FileWriteSystemTime(filename);

	FileWriteString(filename, "Signal", 7);
	FileWriteInt(filename, Signal);
	FileWriteSystemTime(filename);

	FileWriteString(filename, "IBI", 4);
	FileWriteInt(filename, IBI);
	FileWriteSystemTime(filename);
}

/*
*写入警告信息
*filename：文件名，key：产品key，warning：警告信息
*/
void FileWriteWarningData(string filename, int key, int warning)
{
	FileWriteString(filename, "Key:", 5);
	FileWriteInt(filename, key);

	FileWriteString(filename, "Warning:", 9);
	FileWriteInt(filename, warning);
	FileWriteSystemTime(filename);
}
