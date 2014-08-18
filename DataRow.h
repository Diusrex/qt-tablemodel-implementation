#ifndef DATAROW_H
#define DATAROW_H

#include <QVariant>

class DataRow
{
public:
    virtual ~DataRow() { }

    virtual QVariant GetData(int column) const = 0;

    virtual int GetColumnCount() const = 0;

    virtual void DataChanged(const int & column, const QVariant & value) = 0;

    virtual bool CanBeChanged(const int & column) const = 0;
};

#endif // DATAROW_H