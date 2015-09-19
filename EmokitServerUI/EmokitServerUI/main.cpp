#include "emokitserverui.h"
#include <QtWidgets/QApplication>
#include "LogInfo.h"

/*main����*/
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	qInstallMessageHandler(LogInfoOutput);
	EmokitServerUI w;
	w.setFixedSize(417,353);
	w.show();

	return a.exec();
}
