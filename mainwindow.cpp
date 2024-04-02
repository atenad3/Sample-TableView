#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "drive_test.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    prepareDB();
    if(isDBReady_ == true)
        testConnection();
}


void MainWindow::prepareDB()
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName("localhost");
    db.setDatabaseName("test_cells");
    db.setUserName("atefe");
    db.setPassword("atefe1234");


    if (!db.open()) {
        QMessageBox::warning(this, "Warning", lastExtraInfo + "\nPlease check your database connection parameters.");
        isDBReady_ = false;
        return;
    }

    else {
        qDebug() << "connected to db";
        isDBReady_ = true;
        dBConfigs.host = "localhost";
        dBConfigs.name = "test_cells";
        dBConfigs.user = "atefe";
        dBConfigs.pass = "atefe1234";
    }
}


void MainWindow::testConnection()
{
    QString lastExtraInfo;
    readyDB = getDB("Table_Conn", lastExtraInfo);
    model_ = new Drive_Test(this, readyDB);
    ui->tableView->setModel(model_);
}


QSqlDatabase MainWindow::getDB(const QString connName, QString& lastExtraInfo, bool testConn){
    //test that connection with this name is exist before or not.
    QSqlDatabase db = QSqlDatabase::database(connName);
    if (db.isOpen()) {
        qDebug()<<"getDb";
        if (!testConn)
            return db;

        QSqlQuery query(db);
        query.prepare("SELECT 1;");
        if (query.exec())
            return db;
    }

    if (dBConfigs.type == DBTypes_E::MYSQL) {
        qDebug()<<connName;
        // Setting port number is just applied when db.setHostName equals to an IP address such as "127.0.0.1", not "localhost"
        db = QSqlDatabase::addDatabase("QMYSQL", connName);
        db.setPort(dBConfigs.port);
        db.setHostName(dBConfigs.host);
        db.setDatabaseName(dBConfigs.name);
        db.setUserName(dBConfigs.user);
        db.setPassword(dBConfigs.pass);
    }
    else {
        lastExtraInfo = "The program could not create database with type " + DBTypesToStr_Map.value(dBConfigs.type);
        return QSqlDatabase();
    }
    if (!db.open()) {
        if (!db.open()) // Point: Try again, Do not remove
        {
            lastExtraInfo = "ERROR_DB";
            return QSqlDatabase();
        }
    }

    // Success
    lastExtraInfo = "";
    return db;
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushBotton_clicked()
{
    if (!isDBReady_) {
        QMessageBox::warning(this, "Warning", "DB does not prepare successfully!");
        return;
    }
    //db is ok and ready to use. in continue, apply filter for nodeID and fetch data from it.
    model_->showNodeIdInfo(ui->spinBox->value());
    model_->select();
    ui->tableView->resizeColumnsToContents();

}

