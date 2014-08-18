#include "NameNumberInfo.h"

QVariant NameNumberInfo::GetData(int column) const
{
    switch (column)
    {
    case NAME_COLUMN:
        return name;

    case NUMBER_COLUMN:
        return number;

    default:
        return QVariant();
    }
}

void NameNumberInfo::DataChanged(const int & column, const QVariant & value)
{
    if (column == NUMBER_COLUMN)
        number = value.toInt();
}

bool NameNumberInfo::CanBeChanged(const int & column) const
{
    return column == NUMBER_COLUMN;
}