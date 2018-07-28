#include <mastodon.h>
#include <stdio.h>


using namespace std;

Mastodon::Mastodon(int num){
    FILE *file;
	string filename;
	filename=".\\"+to_string(num)+".dat";
	file=fopen(filename.c_str(),"rb");
	fclose(file);

}

Mastodon::~Mastodon(){

}

void Mastodon::SaveAccount(int num,string host,string app){
	string apiaddr;
	apiaddr="https://"+host+"/api/v1/apps";
	string filename;
	filename=".\\"+to_string(num)+".dat";

    FILE *file;

	QNetworkAccessManager *manager=new QNetworkAccessManager((QObject *)this);
	QUrl url(QString::fromStdString(apiaddr));
	QNetworkRequest request(url);
	QNetworkReply *r = manager->get(request);
	request.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");

	QFile certFile(QString::fromStdString(std::string(":/"+host+".crt")));
	certFile.open(QIODevice::ReadOnly);
	QSslCertificate cert(&certFile, QSsl::Pem);
	QSslSocket * sslSocket = new QSslSocket((QObject *)this);
	sslSocket->addCaCertificate(cert);
	QSslConfiguration config = sslSocket->sslConfiguration();
	config.setProtocol(QSsl::TlsV1_2);
	sslSocket->setSslConfiguration(config);
	r->setSslConfiguration(config);

	QUrlQuery params;
	params.addQueryItem("client_name",QString::fromStdString(app));
	params.addQueryItem("redirect_uris","urn:ietf:wg:oauth:2.0:oob");
	params.addQueryItem("scopes","read+write+follow");
	QObject::connect(manager,SIGNAL(finished(QNetworkReply *)), (QObject *)this, SLOT(replyFinished(QNetworkReply *)));
	manager->post(request, params.toString(QUrl::FullyEncoded).toUtf8());
	params.clear();


	apiaddr="https://"+host+"/oauth/token";
	url.setUrl(QString::fromStdString(apiaddr));
	request.setUrl(url);
	params.addQueryItem("client_id",QString::fromStdString(clientid));
	params.addQueryItem("client_secret",QString::fromStdString(clientsecret));
	params.addQueryItem("grant_type","client_credentials");


	file=fopen(filename.c_str(),"wb");
    fclose(file);
}

void Mastodon::replyFinished(QNetworkReply *reply){
	QByteArray data = reply->readAll();
	QString qstr=QString::fromUtf8(data);
	string str=qstr.toStdString();

}
