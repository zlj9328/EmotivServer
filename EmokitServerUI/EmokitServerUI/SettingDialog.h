#ifndef SETTING_DIALOG_H
#define SETTING_DIALOG_H

#include <QDialog>
#include "ui_SettingDialog.h"
#include <QSettings>

#define IP_POINT "/IP"
#define PORT_POINT "/Port"


class SettingDialog : public QDialog
{
	Q_OBJECT

public:
	SettingDialog(QWidget *parent = 0);
	~SettingDialog();

private:
	Ui_SettingDialog ui;

	QSettings *settingConfig;
private slots:
	void on_buttonBox_clicked(QAbstractButton *button);
};




#endif