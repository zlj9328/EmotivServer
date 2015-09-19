/********************************************************************************
** Form generated from reading UI file 'emokitserverui.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMOKITSERVERUI_H
#define UI_EMOKITSERVERUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmokitServerUIClass
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *StopServer;
    QPushButton *StartServer;
    QPushButton *ClearMsgButton;
    QGroupBox *groupBox_2;
    QTextBrowser *ShowInfo;
    QGroupBox *groupBox_3;
    QListView *UserListView;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *EmokitServerUIClass)
    {
        if (EmokitServerUIClass->objectName().isEmpty())
            EmokitServerUIClass->setObjectName(QStringLiteral("EmokitServerUIClass"));
        EmokitServerUIClass->resize(417, 354);
        QIcon icon;
        icon.addFile(QStringLiteral(":/EmokitServerUI/ServerIcon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        EmokitServerUIClass->setWindowIcon(icon);
        centralWidget = new QWidget(EmokitServerUIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 131, 111));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 91, 83));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        StopServer = new QPushButton(layoutWidget);
        StopServer->setObjectName(QStringLiteral("StopServer"));

        gridLayout->addWidget(StopServer, 1, 0, 1, 1);

        StartServer = new QPushButton(layoutWidget);
        StartServer->setObjectName(QStringLiteral("StartServer"));

        gridLayout->addWidget(StartServer, 0, 0, 1, 1);

        ClearMsgButton = new QPushButton(layoutWidget);
        ClearMsgButton->setObjectName(QStringLiteral("ClearMsgButton"));

        gridLayout->addWidget(ClearMsgButton, 2, 0, 1, 1);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(150, 10, 251, 281));
        ShowInfo = new QTextBrowser(groupBox_2);
        ShowInfo->setObjectName(QStringLiteral("ShowInfo"));
        ShowInfo->setGeometry(QRect(10, 20, 231, 251));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 130, 131, 161));
        UserListView = new QListView(groupBox_3);
        UserListView->setObjectName(QStringLiteral("UserListView"));
        UserListView->setGeometry(QRect(10, 20, 111, 131));
        EmokitServerUIClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(EmokitServerUIClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 417, 23));
        EmokitServerUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(EmokitServerUIClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setMovable(false);
        mainToolBar->setFloatable(true);
        EmokitServerUIClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(EmokitServerUIClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        EmokitServerUIClass->setStatusBar(statusBar);

        retranslateUi(EmokitServerUIClass);

        QMetaObject::connectSlotsByName(EmokitServerUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *EmokitServerUIClass)
    {
        EmokitServerUIClass->setWindowTitle(QApplication::translate("EmokitServerUIClass", "EmokitServerUI", 0));
        groupBox->setTitle(QApplication::translate("EmokitServerUIClass", "\346\216\247\345\210\266\345\214\272", 0));
        StopServer->setText(QApplication::translate("EmokitServerUIClass", "\345\201\234\346\255\242", 0));
        StartServer->setText(QApplication::translate("EmokitServerUIClass", "\345\220\257\345\212\250", 0));
        ClearMsgButton->setText(QApplication::translate("EmokitServerUIClass", "\346\270\205\347\251\272\346\266\210\346\201\257\346\241\206", 0));
        groupBox_2->setTitle(QApplication::translate("EmokitServerUIClass", "\346\266\210\346\201\257\346\241\206", 0));
        groupBox_3->setTitle(QApplication::translate("EmokitServerUIClass", "\345\234\250\347\272\277\347\224\250\346\210\267", 0));
    } // retranslateUi

};

namespace Ui {
    class EmokitServerUIClass: public Ui_EmokitServerUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMOKITSERVERUI_H
