#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <sql_common.h>
#include <QMessageBox>
#include <QtSql>
#include "drive_test.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString lastExtraInfo;
    QSqlDatabase getDB(QString connName, QString& lastExtraInfo, bool testConn = true);


private slots:
    void on_pushBotton_clicked();

private:
    Ui::MainWindow *ui;

    bool isDBReady_ = false;
    void prepareDB();
    void testConnection();
    DBConfig dBConfigs;

    QSqlDatabase readyDB;
    Drive_Test* model_;


};
#endif // MAINWINDOW_H
