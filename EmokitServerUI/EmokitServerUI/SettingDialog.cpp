#include "SettingDialog.h"
#include "GlobalVar.h"

SettingDialog::SettingDialog(QWidget *parent) : QDialog(parent)
{
	ui.setupUi(this);
	ui.Port_Edit->setValidator(new QIntValidator(0, 65535, this));

	settingConfig = new QSettings("EmokitServerConfig.ini");

	ui.IP_Edit->setText(settingConfig->value(IP_POINT).toString());
	ui.Port_Edit->setText(settingConfig->value(PORT_POINT).toString());

	if (server_state == SERVER_STATE_START)
	{
		ui.IP_Edit->setEnabled(false);
		ui.Port_Edit->setEnabled(false);
	}

}

SettingDialog::~SettingDialog()
{
	delete settingConfig;
	
}

/*按键信号槽函数*/
void SettingDialog::on_buttonBox_clicked(QAbstractButton *button)
{
	if (ui.buttonBox->button(QDialogButtonBox::Ok) == (QPushButton *)button)
	{
		qDebug("Setting OK");
		udpHelper.m_IP = ui.IP_Edit->text().toStdString();
		udpHelper.m_Port = ui.Port_Edit->text().toInt();		
		
		/*将新的ip和port写入文件*/
		settingConfig->setValue(IP_POINT, QString::fromStdString(udpHelper.m_IP));
		settingConfig->setValue(PORT_POINT, udpHelper.m_Port);
		udpHelper.Unbind();
		udpHelper.InitUDPSocket();
	}
	else if (ui.buttonBox->button(QDialogButtonBox::Cancel) == (QPushButton *)button)
	{
		qDebug("Setting Cancel");
	}
}