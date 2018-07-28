#include "settingui.h"
#include "ui_setting.h"
#include "settingdata.h"
#include "sns.h"

SettingWindow::SettingWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SettingWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window);
}

SettingWindow::~SettingWindow(){
    FILE *file;
    file=fopen(".\\settings.dat","wb");
    fwrite((const void *)&settingdata,sizeof(settingdata),1,file);
    fclose(file);
    delete ui;
}

void SettingWindow::on_fontComboBox_currentFontChanged(const QFont &f){
    QString qstr=f.family();
	settingdata.fontname=qstr.toStdString();
}

void SettingWindow::on_pushButton_clicked(){
    settingdata.insnum++;
}

void SettingWindow::on_spinBox_valueChanged(int arg1){
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
}

void SettingWindow::on_SettingWindow_destroyed()
{
    FILE *file;
    file = fopen(".\\settings.dat","wb");
    fwrite((void *)&settingdata,sizeof(settingdata),1,file);
    fclose(file);
}

void SettingWindow::on_pushButton_2_clicked()
{
    FILE *file;
	std::string host;
	std::string app;
    QString qstr=ui->lineEdit->text();
	host=qstr.toStdString();
	qstr=ui->lineEdit_4->text();
	app=qstr.toStdString();
	sns[ui->spinBox->value()]->RegisterAccount(ui->spinBox->value(),host,app);
}
