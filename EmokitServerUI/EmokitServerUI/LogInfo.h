#ifndef LOGINFO_H
#define LOGINFO_H

#include <QtDebug>
#include <QFile>
#include <QTextStream>

void LogInfoOutput(QtMsgType type, const QMessageLogContext& Context, const QString  &msg);

#endif