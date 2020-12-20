#ifndef DATAMODEL_H
#define DATAMODEL_H

#include <QObject>

class DataModel : public QObject
{
    Q_OBJECT
public:
    explicit DataModel(QObject *parent = nullptr);

    Q_PROPERTY(int salary READ salary WRITE setSalary NOTIFY salaryChanged)

    Q_INVOKABLE void setSalary(int salary){ _salary = salary; _setValue = salary; emit salaryChanged(); }
    Q_INVOKABLE void resetSalary(){ _salary = _setValue; emit salaryChanged(); }

signals:
    void salaryChanged();

public slots:
    void increment() { _salary++; emit salaryChanged(); }

private:
    int _salary;
    int _setValue;
    int salary() { return _salary; }
    // void setSalary(int salary) { _salary = salary; emit salaryChanged(); }

};

#endif // DATAMODEL_H
