/****************************************************************************
****************************************************************************/
#ifndef RECORDSPAGE_H
#define RECORDPAGE_H

#include <QDialog>
#include <QStandardItemModel>

class QFile;
class QLabel;
class QLineEdit;

namespace Ui {
    class RecordsPage;
}

class RecordsPage : public QDialog
{
    Q_OBJECT

  public:
    explicit RecordsPage(QWidget *parent = Q_NULLPTR);
    ~RecordsPage();


  private slots:

  private:
    Ui::RecordsPage *ui;
    QStandardItemModel *csvModel;  
    QFile *file;
};

#endif // RECORDSSPAGE_H
