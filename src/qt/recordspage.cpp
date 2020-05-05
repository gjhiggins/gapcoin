/****************************************************************************
****************************************************************************/

#include "recordspage.h"
#include "ui_recordspage.h"
#include "init.h"
#include "main.h"
#include "util.h"
#include "bitcoingui.h"

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
    csvModel->setColumnCount(8);
    csvModel->setHorizontalHeaderLabels(
        QStringList() << "height" << "difficulty" << "shift" << "adder" << "gapsize" << "merit" << "digits" << "startprime");
    ui->tableView->setModel(csvModel);
    ui->tableView->setColumnWidth(0, 60); // height
    ui->tableView->setColumnWidth(2, 50); // shift
    ui->tableView->setColumnWidth(3, 160); // adder
    ui->tableView->setColumnWidth(4, 50); // gapsize
    ui->tableView->setColumnWidth(5, 50); // merit
    ui->tableView->setColumnWidth(6, 50); // primedigits
    ui->tableView->setColumnWidth(7, 200);
 
    // Open the file from the resources. Instead of the file
    // Need to specify the path to your desired file
    QFile file("gaprecords.csv");
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

