#include "LogInfo.h"
#include "qdatetime.h"

/*日志输出到文件函数*/
void LogInfoOutput(QtMsgType type, const QMessageLogContext& Context, const QString  &msg)
{
	QString txt;
	QString str;

	QDateTime time = QDateTime::currentDateTime();
	str = time.toString();

	switch (type) 
	{
	case QtDebugMsg:
		txt = QString("Debug: %1").arg(msg);
		break;

	case QtWarningMsg:
		txt = QString("Warning: %1").arg(msg);
		break;
	case QtCriticalMsg:
		txt = QString("Critical: %1").arg(msg);
		break;
	case QtFatalMsg:
		txt = QString("Fatal: %1").arg(msg);
		abort();
	}
	txt.append("  ----");
	txt.append(str);
	txt.append("----");

	QFile outFile("LogInfo.txt");
	outFile.open(QIODevice::WriteOnly | QIODevice::Append);
	QTextStream ts(&outFile);
	ts << txt << endl;
}
