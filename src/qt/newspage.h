#ifndef NEWSPAGE_H
#define NEWSPAGE_H

#include <QWidget>
#include <QtWebView>


namespace Ui {
	class NewsPage;
}
class WalletModel;

class NewsPage : public QWidget
{
    Q_OBJECT

public:
    explicit NewsPage(QWidget *parent = 0);
    void setModel(WalletModel *model);


virtual ~NewsPage();

private:
	Ui::NewsPage *ui;
    WalletModel *model;
    QWebView *view;
};

#endif // NEWSPAGE_H

/*
QWebView *view = new QWebView(parent);
view->load(QUrl("http://google.com/"));
view->show();
*/