#include "MyModel.h"

MyModel::MyModel(std::vector<std::unique_ptr<DataRow>> & rowsInfo, QObject * parent /* = 0*/)
    : QAbstractTableModel(parent)
{
    std::swap(this->rowsInfo, rowsInfo);
}

int MyModel::columnCount(const QModelIndex & /*parent = QModelIndex()*/) const
{
    if (rowsInfo.size() == 0)
        return 0;

    // If you will have rows with different columns, then this will need to instead be the max value
    return rowsInfo[0]->GetColumnCount(); 
}


int MyModel::rowCount(const QModelIndex & /* parent = QModelIndex()*/) const
{
    return rowsInfo.size();
}


QVariant MyModel::data(const QModelIndex & index, int role) const
{
    if (!IndexIsValid(index))
        return QVariant();

    if (role == Qt::DisplayRole || role == Qt::EditRole)
        return rowsInfo[index.row()]->GetData(index.column());

    return QVariant();
}


QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role /*= Qt::DisplayRole*/) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    // If you are displaying headers, will want to add more code here
    if (orientation == Qt::Horizontal)
        return QString("Column %1").arg(section);
    else
        return QString("Row %1").arg(section);
}


Qt::ItemFlags MyModel::flags(const QModelIndex & index) const
{
    if (!IndexIsValid(index))
        return Qt::ItemIsEnabled;

    if (rowsInfo[index.row()]->CanBeChanged(index.column()))
        return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;

    return QAbstractTableModel::flags(index);

    /* Optional setting. Makes it so cannot select indexes that can't be changed (need to remove above return as well)
    // If you don't know what this does, look at http://stackoverflow.com/questions/3920307/how-can-i-remove-a-flag-in-c
    return QAbstractTableModel::flags(index) & ~Qt::ItemIsSelectable; 
    */
}

bool MyModel::setData(const QModelIndex & index, const QVariant & value, int role /*= Qt::EditRole*/)
{
    if (IndexIsValid(index) && role == Qt::EditRole) {
        rowsInfo[index.row()]->DataChanged(index.column(), value);
        emit dataChanged(index, index);
        return true;
    }
    return false;
}

bool MyModel::IndexIsValid(const QModelIndex & index) const
{
    return index.isValid() && index.row() < rowCount();
}
