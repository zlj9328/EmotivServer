#ifndef GRAPH_DIALOG_H
#define GRAPH_DIALOG_H

#include <QDialog>
#include <qapplication.h>
#include "ui_GraphDialog.h"
#include "Thread.h"

#define GRAPH_POINT_NUM     350
#define XAXIS_STEP          0.2

class GraphDialog : public QDialog
{
	Q_OBJECT

public:
	GraphDialog(QWidget *parent = 0);
	~GraphDialog();

private:
	void GraphInit();
	void GraphAddData(double dat1, double dat2);

private slots:
	/*Êó±ê²Ù×÷*/
	void mousePress();
	void mouseWheel();
	void selectionChanged();

	void GraphUpdateData(int channel1, int channel2);

private:
	Ui_GraphDialog ui;

	QCPGraph *Graph_Channel1;
	QCPGraph *Graph_Channel2;
	double xAxis_num;
};

#endif