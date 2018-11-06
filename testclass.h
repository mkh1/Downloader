#ifndef TESTCLASS_H
#define TESTCLASS_H

#include <QObject>

class Testclass : public QObject
{
    Q_OBJECT
public:
    explicit Testclass(QObject *parent = 0);

signals:

public slots:
};

#endif // TESTCLASS_H
