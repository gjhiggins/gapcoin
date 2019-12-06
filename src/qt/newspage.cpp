#include "ui_newspage.h"
#include "guiutil.h"
#include "bitcoingui.h"
#include "util.h"
#include "main.h"

NewsPage::NewsPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewsPage),
    model(0)
{
    ui->setupUi(this);
    view = new QWebEngineView(this);
    view->load(url);


}
    void NewsPage::setModel(WalletModel *model)
{
    this->model = model;
    if(!model)
        return;
}

NewsPage::~NewsPage()
{
    delete ui;
}
