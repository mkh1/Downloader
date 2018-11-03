#ifndef CLASS_DOWNLOADER_H
#define CLASS_DOWNLOADER_H

#include <QObject>
#include <QUrl>
#include <QString>

class Class_downloader : public QObject
{
    Q_OBJECT
public:
    Class_downloader(QUrl url);

    void Add_Url(const QUrl url);
    void Add_Url(const QString url);

signals:

public slots:


private:
    QUrl url;
};

#endif // CLASS_DOWNLOADER_H
