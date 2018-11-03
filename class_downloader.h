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
    Class_downloader(QString url);
    
    void Start_Download();
    void Set_speed(double speed);

signals:

public slots:
    
    
private:
    QUrl url;
    double speed;
};

#endif // CLASS_DOWNLOADER_H
