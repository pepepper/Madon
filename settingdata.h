#ifndef SETTINGDATA_H
#define SETTINGDATA_H
#include "sns.h"
typedef struct{
	std::string fontname;
    int insnum;
}SETTINGDATA;

extern SETTINGDATA settingdata;
extern std::vector<std::shared_ptr<SNS>> sns;
#endif // SETTINGDATA_H
