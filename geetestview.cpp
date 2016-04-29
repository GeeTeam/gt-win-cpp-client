//special thanks xh286286

#include "geetestview.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonDocument>
#include <QWebPage>
#include <QWebFrame>
#include <QDesktopServices>

GeeTestView::GeeTestView(QWidget *parent)
	: QWebView(parent)
{
	QWebFrame *frame = page()->mainFrame();
	frame->setScrollBarPolicy(Qt::Horizontal, Qt::ScrollBarAlwaysOff);
	frame->setScrollBarPolicy(Qt::Vertical, Qt::ScrollBarAlwaysOff);
	frame->addToJavaScriptWindowObject("JSInterface", this);


	QObject::connect(this, &QWebView::linkClicked, [](const QUrl & url){
		//__debugbreak();
		qDebug() << url;

		QDesktopServices::openUrl( url);
	});

}

GeeTestView::~GeeTestView()
{

}

void GeeTestView::gtReady(){
	qDebug() << "gtReady";
	emit gtLoadReady(); 
}
void GeeTestView::gtCloseWindow(){
	qDebug() << "gtCloseWindow";
	deleteLater();
}
void GeeTestView::gtCallBack(QString code, QString result, QString message) {
	qDebug() << "gtCallBack";
	qDebug() << code;
	qDebug() << result;
	qDebug() << message;
	if (code == "1") emit gtResultSended(result);
	this->result = result; 
    //result 用于二次验证的回调 请搭建二次验证的api2
}
bool GeeTestView::loadGeeTest() {
	if (flag_loading) return false;
 
	result = "";
	flag_loading = true;

	/* fetch gt/challenge/success data from custom server

     API1

     jo = QJsonObject({"challenge":"***","gt":"***","success":1})

	*/

	qDebug() << jo;
	if (jo["success"].toInt() != 1)  {
		flag_loading = false;
		return false;
	}

	int x = 1;
	
	QString url1 = "http://static.geetest.com/static/appweb/app-index.html?gt=[gt]&challenge=[challenge]&width=[width]";
	url1.replace("[gt]", jo["gt"].toString());
	url1.replace("[challenge]", jo["challenge"].toString());
	url1.replace("[width]", QString::number(width()) );

	load(url1);
	flag_loading = false;
	return true;
}