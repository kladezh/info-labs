#include "tablemodel.h"

TableModel::TableModel(QObject* parent) : QAbstractTableModel(parent)
{
    _data.resize(ROW_COUNT);
    for (auto& row : _data) {
        row.resize(COLUMN_COUNT);
    }
}

int TableModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return this->ROW_COUNT;
}

int TableModel::columnCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return this->COLUMN_COUNT;
}

QVariant TableModel::headerData(const int section, Qt::Orientation orientation, const int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        return QString::number(section + 1);
    }

    return QVariant();
}

QVariant TableModel::data(const QModelIndex& index, int role) const
{
    if (role == Qt::DisplayRole) {
        return _data[index.row()][index.column()];
    }

    return QVariant();
}

bool TableModel::setData(const QModelIndex& index, const QVariant& value, const int role)
{
    if (role == Qt::EditRole) {
        _data[index.row()][index.column()] = value.toInt();

        emit(dataChanged(index, index));
        return true;
    }

    return false;
}
