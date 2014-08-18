#ifndef MYMODEL_H
#define MYMODEL_H

#include "DataRow.h"

#include <memory>
#include <QAbstractTableModel>
#include <vector>

class QSpinBox;

class MyModel : public QAbstractTableModel
{
public:
    // Will take ownership of this vector
    MyModel(std::vector<std::unique_ptr<DataRow>> & rowsInfo, QObject * parent = 0);


    // Basic required information
    int columnCount(const QModelIndex & parent = QModelIndex()) const override;
    int rowCount(const QModelIndex & parent = QModelIndex()) const override;
    QVariant data(const QModelIndex & index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation,
        int role = Qt::DisplayRole) const override;


    // Make it editable
    Qt::ItemFlags flags(const QModelIndex & index) const override;
    bool setData(const QModelIndex & index, const QVariant & value,
        int role = Qt::EditRole) override;

private:
    bool IndexIsValid(const QModelIndex & index) const;

    // Will be stored with rowsInfo[row] being responsible for the displayed at the given row.
    std::vector<std::unique_ptr<DataRow>> rowsInfo;
};

#endif // MYMODEL_H