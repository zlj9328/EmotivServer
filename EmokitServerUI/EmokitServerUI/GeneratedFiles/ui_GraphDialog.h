/********************************************************************************
** Form generated from reading UI file 'GraphDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHDIALOG_H
#define UI_GRAPHDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_GraphDialog
{
public:
    QGroupBox *groupBox;
    QCustomPlot *qcustomplot;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(637, 371);
        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 611, 351));
        qcustomplot = new QCustomPlot(groupBox);
        qcustomplot->setObjectName(QStringLiteral("qcustomplot"));
        qcustomplot->setGeometry(QRect(10, 20, 591, 321));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "\346\212\230\347\272\277\345\233\276", 0));
        groupBox->setTitle(QApplication::translate("Dialog", "\351\200\232\351\201\223\344\277\241\346\201\257:", 0));
    } // retranslateUi

};

namespace Ui {
	class GraphDialogUiClass : public Ui_GraphDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHDIALOG_H
