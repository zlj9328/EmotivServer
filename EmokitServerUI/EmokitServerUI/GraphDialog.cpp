#include "GraphDialog.h"
#include "GlobalVar.h"

GraphDialog::GraphDialog(QWidget *parent) : QDialog(parent)
{
	ui.setupUi(this);
	GraphInit();
}

GraphDialog::~GraphDialog()
{
	graph_key = -1;
}

/*折线图初始化函数*/
void GraphDialog::GraphInit()
{
	QVector<double> x(1), y(1);
	x[0] = 0.0;
	y[0] = 8000.0;

	xAxis_num = 0.0;

	connect(ui.qcustomplot, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(mousePress()));//连接鼠标点击信号和槽
	connect(ui.qcustomplot, SIGNAL(mouseWheel(QWheelEvent*)), this, SLOT(mouseWheel()));//连接鼠标滚轮信号和槽
	connect(ui.qcustomplot, SIGNAL(selectionChangedByUser()), this, SLOT(selectionChanged()));//连接曲线选择信号和槽
	//设置交互方式
	ui.qcustomplot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes |	QCP::iSelectLegend | QCP::iSelectPlottables);

	QBrush qBrush(QColor(240, 240, 240));//设置背景色
	ui.qcustomplot->setBackground(qBrush);

	ui.qcustomplot->legend->setVisible(true);
	ui.qcustomplot->xAxis->setLabel("Time Axis (t/s)");//设置ｘ轴
	ui.qcustomplot->xAxis->setTicks(false);

	ui.qcustomplot->yAxis->setLabel("EEG Channel");//设置ｙ轴
	ui.qcustomplot->yAxis->setAutoTicks(true);
	ui.qcustomplot->yAxis->setAutoTickStep(true);
	ui.qcustomplot->yAxis->setAutoSubTicks(true);
	ui.qcustomplot->yAxis->setRange(8000.0, 10000.0);

	Graph_Channel1 = ui.qcustomplot->addGraph();
	Graph_Channel2 = ui.qcustomplot->addGraph();

	//    QCPScatterStyle QCPcs1(QCPScatterStyle::ssSquare, QColor(255,0,0),QColor(255,0,0),3);//设置折线图的点的形状及颜色
	QPen qPen1(QColor(255, 0, 0));
	//    graph_FC5->setScatterStyle(QCPcs1);
	Graph_Channel1->setPen(qPen1);//设置画笔颜色
	Graph_Channel1->setData(x, y);
	Graph_Channel1->setName(QString("F3"));

	//    QCPScatterStyle QCPcs2(QCPScatterStyle::ssCircle, QColor(0,255,0),QColor(0,255,0),3);//设置折线图的点的形状及颜色
	QPen qPen2(QColor(0, 255, 0));
	//    graph_FC6->setScatterStyle(QCPcs2);
	Graph_Channel2->setPen(qPen2);//设置画笔颜色
	Graph_Channel2->setData(x, y);
	Graph_Channel2->setName(QString("F4"));

	ui.qcustomplot->rescaleAxes(true);//坐标重新适应,该函数为槽函数
	ui.qcustomplot->replot();//重绘函数
}

/*折线图添加数据函数*/
void GraphDialog::GraphAddData(double dat1, double dat2)
{
	QVector<double> x(2), y(2);
	xAxis_num += XAXIS_STEP;//ｘ坐标自增

	if (xAxis_num / XAXIS_STEP > GRAPH_POINT_NUM)
	{
		Graph_Channel1->clearData();
		Graph_Channel2->clearData();
		xAxis_num = 0.0;
	}

	y[0] = dat1;
	y[1] = dat2;
	x[0] = xAxis_num;
	x[1] = xAxis_num;

	Graph_Channel1->addData(x[0], y[0]);
	Graph_Channel2->addData(x[1], y[1]);

	ui.qcustomplot->rescaleAxes(true);//从新适应坐标
	ui.qcustomplot->replot();
}

/*
*折线图更新数据函数
*channel1，channel2为通道的数据
*/
void GraphDialog::GraphUpdateData(int channel1, int channel2)
{
	GraphAddData(channel1, channel2);
}



/**
* @brief MainWindow::mousePress
*　鼠标点击
*/
void GraphDialog::mousePress()
{
	// if an axis is selected, only allow the direction of that axis to be dragged
	// if no axis is selected, both directions may be dragged
	if (ui.qcustomplot->xAxis->selectedParts().testFlag(QCPAxis::spAxis))
	{
		ui.qcustomplot->axisRect()->setRangeDrag(ui.qcustomplot->xAxis->orientation());
	}
	else if (ui.qcustomplot->yAxis->selectedParts().testFlag(QCPAxis::spAxis))
	{
		ui.qcustomplot->axisRect()->setRangeDrag(ui.qcustomplot->yAxis->orientation());
	}
	else
	{
		ui.qcustomplot->axisRect()->setRangeDrag(Qt::Horizontal | Qt::Vertical);
	}
}

/**
* @brief MainWindow::mouseWheel
*　鼠标滚轮
*/
void GraphDialog::mouseWheel()
{
	// if an axis is selected, only allow the direction of that axis to be zoomed
	// if no axis is selected, both directions may be zoomed
	if (ui.qcustomplot->xAxis->selectedParts().testFlag(QCPAxis::spAxis))
	{
		ui.qcustomplot->axisRect()->setRangeZoom(ui.qcustomplot->xAxis->orientation());
	}
	else if (ui.qcustomplot->yAxis->selectedParts().testFlag(QCPAxis::spAxis))
	{
		ui.qcustomplot->axisRect()->setRangeZoom(ui.qcustomplot->yAxis->orientation());
	}
	else
	{
		ui.qcustomplot->axisRect()->setRangeZoom(Qt::Horizontal | Qt::Vertical);
	}
}

/**
* @brief MainWindow::selectionChanged
* 曲线选择
*/
void GraphDialog::selectionChanged()
{
	/*
	normally, axis base line, axis tick labels and axis labels are selectable separately, but we want
	the user only to be able to select the axis as a whole, so we tie the selected states of the tick labels
	and the axis base line together. However, the axis label shall be selectable individually.

	The selection state of the left and right axes shall be synchronized as well as the state of the
	bottom and top axes.

	Further, we want to synchronize the selection of the graphs with the selection state of the respective
	legend item belonging to that graph. So the user can select a graph by either clicking on the graph itself
	or on its legend item.
	*/

	// make top and bottom axes be selected synchronously, and handle axis and tick labels as one selectable object:
	if (ui.qcustomplot->xAxis->selectedParts().testFlag(QCPAxis::spAxis) || ui.qcustomplot->xAxis->selectedParts().testFlag(QCPAxis::spTickLabels) ||
		ui.qcustomplot->xAxis2->selectedParts().testFlag(QCPAxis::spAxis) || ui.qcustomplot->xAxis2->selectedParts().testFlag(QCPAxis::spTickLabels))
	{
		ui.qcustomplot->xAxis2->setSelectedParts(QCPAxis::spAxis | QCPAxis::spTickLabels);
		ui.qcustomplot->xAxis->setSelectedParts(QCPAxis::spAxis | QCPAxis::spTickLabels);
	}
	// make left and right axes be selected synchronously, and handle axis and tick labels as one selectable object:
	if (ui.qcustomplot->yAxis->selectedParts().testFlag(QCPAxis::spAxis) || ui.qcustomplot->yAxis->selectedParts().testFlag(QCPAxis::spTickLabels) ||
		ui.qcustomplot->yAxis2->selectedParts().testFlag(QCPAxis::spAxis) || ui.qcustomplot->yAxis2->selectedParts().testFlag(QCPAxis::spTickLabels))
	{
		ui.qcustomplot->yAxis2->setSelectedParts(QCPAxis::spAxis | QCPAxis::spTickLabels);
		ui.qcustomplot->yAxis->setSelectedParts(QCPAxis::spAxis | QCPAxis::spTickLabels);
	}

	// synchronize selection of graphs with selection of corresponding legend items:
	for (int i = 0; i<ui.qcustomplot->graphCount(); ++i)
	{
		QCPGraph *graph = ui.qcustomplot->graph(i);
		QCPPlottableLegendItem *item = ui.qcustomplot->legend->itemWithPlottable(graph);
		if (item->selected() || graph->selected())
		{
			item->setSelected(true);
			graph->setSelected(true);
		}
	}
}