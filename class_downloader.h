#ifndef CLASS_DOWNLOADER_H
#define CLASS_DOWNLOADER_H

#include <QObject>

class Class_downloader : public QObject
{
    Q_OBJECT
public:
    explicit Class_downloader(QObject *parent = nullptr);

signals:

public slots:
};

#endif // CLASS_DOWNLOADER_H