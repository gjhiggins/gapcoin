/****************************************************************************
****************************************************************************/

#include <qt/recordspage.h>
#include <qt/forms/ui_recordspage.h>
#include <init.h>
#include <main.h>
#include <util.h>
#include <qt/guiutil.h>
#include <qt/bitcoingui.h>

#include <QtWidgets>
#include <QDialog>
#include <QFile>
#include <QTextStream>
#include <QList>
#include <QStandardItemModel>
#include <QStandardItem>

RecordsPage::RecordsPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RecordsPage)
{
    ui->setupUi(this);

    csvModel = new QStandardItemModel(this);
    csvModel->setColumnCount(9);
    csvModel->setHorizontalHeaderLabels(
        QStringList() << "height" << "date" << "difficulty" << "shift" << "adder" << "gapsize" << "merit" << "digits" << "startprime");
    ui->tableView->setModel(csvModel);
    ui->tableView->setColumnWidth(0, 60); // height
    ui->tableView->setColumnWidth(1, 80); // date
    ui->tableView->setColumnWidth(3, 50); // shift
    ui->tableView->setColumnWidth(4, 160); // adder
    ui->tableView->setColumnWidth(5, 50); // gapsize
    ui->tableView->setColumnWidth(6, 50); // merit
    ui->tableView->setColumnWidth(7, 50); // primedigits
    ui->tableView->setColumnWidth(8, 200);
 
    // Prefer gaprecords data in datadir
    boost::filesystem::path datadirGapRecordsPath = GetDataDir() / "gaprecords.csv";
    QString datadirGapRecords(GUIUtil::boostPathToQString(datadirGapRecordsPath));
    // otherwise default to gaprecords data in the resources.
    QString resourceGapRecords(":/data/gaprecords");
    QFile file(QFile::exists(datadirGapRecords)? datadirGapRecords : resourceGapRecords);

    if ( !file.open(QFile::ReadOnly | QFile::Text) ) {
        qDebug() << "File does not exist.";
    } else {
        qDebug() << "Opening file.";
        // Create a thread to retrieve data from a file
        QTextStream in(&file);
        //Reads the data up to the end of file
        while (!in.atEnd())
        {
            QString line = in.readLine();
            // Adding to the model in line with the elements
            QList<QStandardItem *> standardItemsList;
            // consider that the line separated by semicolons into columns
            for (QString item : line.split(",")) {
                standardItemsList.append(new QStandardItem(item));
            }
            csvModel->insertRow(csvModel->rowCount(), standardItemsList);
        }
        file.close();
    }
}

RecordsPage::~RecordsPage()
{
    delete ui;
}

