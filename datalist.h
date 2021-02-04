#ifndef DATALIST_H
#define DATALIST_H

#include <QObject>
#include <QVariantList>
#include "datamodel.h"


class DataList : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QVariantList data READ data)

public:
    explicit DataList(QObject *parent = nullptr);

    QVariantList data() { return _dataList; }

    void add(DataModel* model) { _dataList.append(QVariant::fromValue(model)); }

signals:

private:
    QVariantList _dataList;

};

#endif // DATALIST_H
