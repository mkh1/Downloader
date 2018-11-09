#ifndef CLASS_DOWNLOADER_H
#define CLASS_DOWNLOADER_H

#include <QObject>
#include <QUrl>
#include <QString>
#include <QNetworkAccessManager>
#include <QFile>

class Class_downloader : public QObject
{
    Q_OBJECT
public:
    //constructors
    Class_downloader(QObject *parent = 0);
    Class_downloader(QUrl url);
    Class_downloader(QString url);
    
    //setters
    void Set_Url(QString url);
    void Start_Download();
    void Set_Speed(double speed);
    void Set_Name_File(QString name);
    void Set_Path_File(QString path);

signals:

public slots:
    
    
private:
    QNetworkAccessManager manager;
    QUrl url;
    double speed;
    QNetworkReply *currentDownload;
    QTime downloadTime;
    QFile output;
    QString path;
    QString file_name;
    QString file_path;

    void Init();
    void Set_Output_default();
    void Set_Output(QString path , QString name);
};

#endif // CLASS_DOWNLOADER_H
