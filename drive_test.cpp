#include "drive_test.h"

// #include <QAbstractTableModel>



Drive_Test::Drive_Test(QObject *parent, QSqlDatabase db)
    : QSqlTableModel(parent, db)
    , db_(db)
{
}


void Drive_Test::showNodeIdInfo(int nodeId){
    QString queryStr = QString("SELECT * FROM Drive_Test WHERE `Node Id` = %1;").arg(nodeId);

    // QSqlQueryModel::setQuery(queryStr, db_);
    setQuery(queryStr, db_);

    // Set headers and tooltips
    setHeadersAndTooltips();
}


void Drive_Test::setHeadersAndTooltips()
{
    // Define a map for column index and its corresponding header data
    QMap<int, QString> headerDataMap;
    headerDataMap[DBColIdx_E::Timestamp] = tr("Timestamp");
    headerDataMap[DBColIdx_E::NodeId] = tr("Node Identity");
    headerDataMap[DBColIdx_E::Latitude] = tr("Node Latitude");
    headerDataMap[DBColIdx_E::Longitude] = tr("Node Longitude");
    headerDataMap[DBColIdx_E::Altitude] = tr("Altitude");
    headerDataMap[DBColIdx_E::servTech] = tr("Server Tech");
    headerDataMap[DBColIdx_E::servArfcn] = tr("Absolute Radio Frequency Channel Number");
    headerDataMap[DBColIdx_E::servCode] = tr("Server Code");
    headerDataMap[DBColIdx_E::sigPowS] = tr("Signal Power");
    headerDataMap[DBColIdx_E::sigQualS] = tr("Signal Quality");
    headerDataMap[DBColIdx_E::sigQualSName] = tr("Signal Quality Name");

    // Loop through the map and set header data and tooltips
    QMap<int, QString>::const_iterator it;
    for (it = headerDataMap.constBegin(); it != headerDataMap.constEnd(); ++it) {
        setHeaderData(it.key(), Qt::Horizontal, it.value());
        setHeaderData(it.key(), Qt::Horizontal, it.value(), Qt::ToolTipRole);
    }
}

QVariant Drive_Test::data(const QModelIndex& index, int role) const
{
    // QVariant value = QSqlTableModel::data(index, role);
    QVariant value = QSqlTableModel::data(index, role);
    return value;
}

Qt::ItemFlags Drive_Test::flags(const QModelIndex& index) const
{
    Q_UNUSED(index);

    Qt::ItemFlags flags = Qt::ItemIsSelectable | Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled | Qt::ItemIsEnabled;
    return flags;
}
