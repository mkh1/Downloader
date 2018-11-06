#ifndef DOWNLOADER_CLASS_H
#define DOWNLOADER_CLASS_H

#include <QObject>

class Downloader_Class : public QObject
{
    Q_OBJECT
public:
    explicit Downloader_Class(QObject *parent = nullptr);

signals:

public slots:
};

#endif // DOWNLOADER_CLASS_H
