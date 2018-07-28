#include "sns.h"
#include "mastodon.h"
#include "settingdata.h"

SNS::SNS(int settingnum){
    FILE *file;
    char service[128];
	std::string filename;
	filename=".\\"+std::to_string(settingnum)+".dat";

	file=fopen(filename.c_str(),"rb");
    fread((void *)service,sizeof(service),1,file);
    fclose(file);

    if(strcmp(service,"Mastodon"))serviceclass=new Mastodon(settingnum);
}

SNS::~SNS(){
}

void SNS::RegisterAccount(int num,std::string host,std::string app){
	return;
}

