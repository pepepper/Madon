#ifndef SNS_H
#define SNS_H
#include <string>

class SNS
{
public:
    SNS(int);
	~SNS();
	virtual void RegisterAccount(int,std::string,std::string);
};

#endif // SNS_H
