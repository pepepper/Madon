#ifndef MASTODON_H
#define MASTODON_H
#include "sns.h"
#include <string>
#include <QUrlQuery>
#include <QtNetwork>
class Mastodon : SNS
{
public:
    explicit Mastodon(int);
    ~Mastodon();
	void SaveAccount(int,std::string,std::string);
	private:
	std::string token;
	std::string clientid;
	std::string clientsecret;
	void replyFinished(QNetworkReply *reply);
};

#endif // MASTODON_H
