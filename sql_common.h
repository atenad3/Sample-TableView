#ifndef SQL_COMMON_H
#define SQL_COMMON_H

#endif // SQL_COMMON_H

#define DB_SQLTYPE_SQLITE "SQLITE"
#define DB_SQLTYPE_MYSQL "MYSQL"
#define DB_SQLTYPE_SQLSERVER "SQLSERVER"

// Constant
const int MYSQL_DEFAULTPORT_C = 3306;
const QString MYSQL_DEFAULTUSER_C = "root";

/*#define ERROR_DB QString::fromStdString(__FILE__) + ", " + QString::fromStdString(__FUNCTION__) + ", line " + QString::number(__LINE__) + ": " + db.lastError().text()
#define ERROR_QUERY QString::fromStdString(__FILE__) + ", " + QString::fromStdString(__FUNCTION__) + ", line " + QString::number(__LINE__) + ": " + query.lastError().text() */


enum class DBTypes_E {
    MYSQL,
    SQLite,
    SQLServer
};


static QMap<DBTypes_E, QString> DBTypesToStr_Map {
{ DBTypes_E::MYSQL, DB_SQLTYPE_MYSQL },
{ DBTypes_E::SQLite, DB_SQLTYPE_SQLITE },
{ DBTypes_E::SQLServer, DB_SQLTYPE_SQLSERVER },
};

static QMap<QString, DBTypes_E> StrToDBTypes_Map {
{ DB_SQLTYPE_MYSQL, DBTypes_E::MYSQL },
{ DB_SQLTYPE_SQLITE, DBTypes_E::SQLite },
{ DB_SQLTYPE_SQLSERVER, DBTypes_E::SQLServer },
};



// Structure
struct DBConfig {
    QString appPath = "";
    DBTypes_E type = DBTypes_E::MYSQL;
    QString host = "localhost";
    int port = MYSQL_DEFAULTPORT_C;
    QString name = "";
    QString user = MYSQL_DEFAULTUSER_C;
    QString pass;
};
