#include "mainwindow.h"
#include <QApplication>
#include "settingdata.h"
#include "sns.h"
SETTINGDATA settingdata={0};
std::vector<std::shared_ptr<SNS>> sns();

void LoadSetting(){
    FILE *file;
    file=fopen(".\\settings.dat","rb");
    fread((void *)&settingdata,sizeof(settingdata),1,file);
    fclose(file);
}

int main(int argc,char *argv[]){
    int ret;
	LoadSetting();
	sns.resize(settingdata.insnum);
    for(int i=0;i<settingdata.insnum;i++){
		sns[i]=new SNS(i);
    }

    QApplication a(argc,argv);
	QFont font(QString::fromStdString(settingdata.fontname));
    a.setFont(font);
    MainWindow w;
    w.show();
    ret = a.exec();

	~sns();
    return ret;
}
