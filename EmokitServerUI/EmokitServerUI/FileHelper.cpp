#include"FileHelper.h"
#include <sstream>

/*
*��ϵͳʱ��д���ļ�
*name:�ļ���
*/
void FileWriteSystemTime(string name)
{
	time_t timep;
	tm date_time;
	time(&timep);
	date_time = *localtime(&timep);//��ȡϵͳʱ��
	ofstream out(name, ios::app);//д����

	out << '\t' << '\t' << '\t';

	out << "----";
	out << date_time.tm_year + 1900 << "-" << date_time.tm_mon + 1 << "-" << date_time.tm_mday << "|";//дʱ�䵽�ı�
	out << date_time.tm_hour << ":" << date_time.tm_min << ":" << date_time.tm_sec;
	out << "----";
	out << endl;
	out.close();
}

/*
*��char����д���ļ�
*name:�ļ�����str:д������ݣ�len:���ݳ���
*/
void FileWriteString(string name, const char *str, int len)
{
	ofstream out(name, ios::app);//д����
	out.write(str, len);
	out << '\t';
	out.close();
}

/*
*��char����д���ļ�
*name:�ļ�����int:д���int������
*/
void FileWriteInt(string name, int dat)
{
	char buf[6];
	itoa(dat,buf,10);
	FileWriteString(name, buf, strlen(buf));
}

/*
*�����ļ�����ƴ��
*return���ļ���
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
*д��ͨ���������ļ�
*channel1:ͨ�����ƣ�dat1:ͨ�����ݣ�channel2:ͨ�����ƣ�dat2:ͨ������
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
*���ĵ�����д���ļ�
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
*д�뾯����Ϣ
*filename���ļ�����key����Ʒkey��warning��������Ϣ
*/
void FileWriteWarningData(string filename, int key, int warning)
{
	FileWriteString(filename, "Key:", 5);
	FileWriteInt(filename, key);

	FileWriteString(filename, "Warning:", 9);
	FileWriteInt(filename, warning);
	FileWriteSystemTime(filename);
}
