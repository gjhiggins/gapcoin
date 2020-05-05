#ifndef NOTARYPAGE_H
#define NOTARYPAGE_H

//#include "uint256.h"

#include <QWidget>

namespace Ui {
    class NotaryPage;
}
class WalletModel;
class ClientModel;

QT_BEGIN_NAMESPACE
class QMenu;
QT_END_NAMESPACE

class NotaryPage : public QWidget
{
    Q_OBJECT

public:
    explicit NotaryPage(QWidget *parent = 0);
    ~NotaryPage();

    void setModel(WalletModel *model);
    void setClientModel(ClientModel *model);

    void setNotaryFileName(QString fileName);

public slots:
    void setSearchResults(std::vector<std::pair<std::string, int> > txResults);
    void showNotaryTxResult(std::string txID, std::string txError);

private slots:
    void calculateNotaryID();
    void on_searchNotaryButton_clicked();

    void on_selectFileButton_clicked();
    void on_sendNotaryButton_clicked();

    // Context menu
    void contextualMenu(const QPoint &point);
    void onCopyTxID();

    void on_calcNotaryIDbutton_clicked();

private:
    Ui::NotaryPage *ui;
    WalletModel *model;
    ClientModel *clientModel;
    QMenu *contextMenu;

    std::string hashFile(std::string fileName);
};

#endif // NOTARYPAGE_H
