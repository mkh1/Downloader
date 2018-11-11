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
//    ~Class_downloader();
    Class_downloader(QUrl url);
    Class_downloader(QString url);
    
    //setters
    void Set_Url(QString url);
    void Start_Download();
    void Set_Speed(double speed);
    void Set_Output(QString path , QString name);

    //getters
    QString Get_Name_File();
    QString Get_Path_File();

    qint64 getSpeed() const;
    void setSpeed(const qint64 &value);

signals:
    void finished();

public slots:
    void downloadProgress(qint64 bytesReceived, qint64 bytesTotal);
    void downloadFinished();
    void downloadReadyRead();
    
    
private:
    QNetworkAccessManager manager;
    QUrl url;
    qint64 set_speed;
    QNetworkReply *currentDownload;
    QTime downloadTime;
    QFile output;
    QString path;
    QString file_name;
    QString file_path;
    QString Error;
    QString speed;
    bool error;

    void Init();
    void Set_Output_default();

};

#endif // CLASS_DOWNLOADER_H
