#ifndef GEETESTVIEW_H
#define GEETESTVIEW_H

#include <QWebView>

class GeeTestView : public QWebView
{
	Q_OBJECT

public:
	GeeTestView(QWidget *parent = 0);
	~GeeTestView();
	
	bool loadGeeTest();

	QString result;
public slots:
	void gtReady();	
	void gtCloseWindow();
	void gtCallBack(QString code, QString result, QString message);
signals:
	void gtLoadReady();
	void gtResultSended(QString result);
private:
	bool flag_loading = false;
};

#endif // GEETESTVIEW_H
