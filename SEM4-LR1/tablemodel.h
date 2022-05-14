#pragma once

#include <QObject>
#include <QAbstractTableModel>

class TableModel : public QAbstractTableModel
{
	Q_OBJECT

public:
	TableModel(QObject *parent = Q_NULLPTR);

    int rowCount(const QModelIndex& parent) const override;
    int columnCount(const QModelIndex& parent) const override;

    QVariant headerData(const int section, Qt::Orientation orientation, const int role = Qt::DisplayRole) const override;

    QVariant data(const QModelIndex& index, const int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex& index, const QVariant& value, const int role = Qt::EditRole) override;

private:
    const int ROW_COUNT = 10;
    const int COLUMN_COUNT = 10;

    QList<QList<int>> _data;
};
