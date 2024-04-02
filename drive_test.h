#ifndef DRIVE_TEST_H
#define DRIVE_TEST_H


#include <QObject>
#include <QPair>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlQueryModel>


class Drive_Test : public QSqlTableModel
{
    Q_OBJECT
public:
    explicit Drive_Test(QObject *parent = nullptr, QSqlDatabase db = QSqlDatabase());
    // Enums
    enum DBColIdx_E : int {
        Id,
        Timestamp,
        NodeId,
        Latitude,
        Longitude,
        Altitude,
        servTech,
        servArfcn,
        servCode,
        servPlmnId,
        servLac,
        servRac,
        servCellId,
        sigTechS,
        sigPowS,
        sigPowSName,
        sigQualS,
        sigQualSName,
        sigRSSIS,
        sigRSSISName,
        sigSINRS,
        sigSINRSName,
        color,
        colorName,
        colorValue,
        colorParamName,
    };

    // Functions
    void showNodeIdInfo(int nodeId);
    void setHeadersAndTooltips();
    QVariant data(const QModelIndex& index, int role) const;

protected:
    Qt::ItemFlags flags(const QModelIndex& index) const;

private:
    QSqlDatabase db_;

signals:
};

#endif // DRIVE_TEST_H
