#include "class_downloader.h"

#include <QFileInfo>
#include <QString>
#include <QNetworkReply>
#include <stdio.h>
#include <stdlib.h>


Class_downloader::Class_downloader(QObject *parent)
    : QObject(parent)
{
}


Class_downloader::Class_downloader(QUrl url)
{
    this->url=url;
}

Class_downloader::Class_downloader(QString url)
{
    this->url.setUrl(QString(QUrl::toPercentEncoding(url, "/:")));
    Init();
}


QString Class_downloader::Get_Name_File()
{
    return this->file_name;
}
QString Class_downloader::Get_Path_File()
{
    return this->file_path;
}

qint64 Class_downloader::getSpeed() const
{
    return this->set_speed;
}

void Class_downloader::setSpeed(const qint64 &value)
{
    currentDownload->setReadBufferSize(value);
}

void Class_downloader::downloadProgress(qint64 bytesReceived, qint64 bytesTotal)
{
    if (currentDownload->error()) {
        // download failed
        fprintf(stderr, "Failed: %s\n", qPrintable(currentDownload->errorString()));
    }
    double speed = bytesReceived * 1000.0 / downloadTime.elapsed();
    QString unit;
    if (speed < 1024) {
        unit = "bytes/sec";
    } else if (speed < 1024*1024) {
        speed /= 1024;
        unit = "kB/s";
    } else {
        speed /= 1024*1024;
        unit = "MB/s";
    }
    qDebug() << QString::number(speed)<<" "<<unit<<"  _"<<QString::number(bytesReceived)<<"  _"<<QString::number(bytesTotal);
    this->speed=QString::number(speed)+unit;
}

void Class_downloader::downloadFinished()
{



    if (currentDownload->error()) {
        // download failed
        fprintf(stderr, "Failed: %s\n", qPrintable(currentDownload->errorString()));
    } else {
        printf("Succeeded.\n");
    }

    emit finished();
//    this->error=true;
//    qDebug() << error ;
}

void Class_downloader::downloadReadyRead()
{
    output.open(QIODevice::WriteOnly);
    this->output.write(currentDownload->readAll());
}

void Class_downloader::Init()
{
//    this->error=false;
//    qDebug() << error ;
    Set_Output_default();
}




void Class_downloader::Set_Output_default()
{
    QString path = this->url.path();
    QString basename = QFileInfo(path).fileName();
    Set_Output("",basename);
}

void Class_downloader::Set_Output(QString path, QString name)
{
//    qDebug() << extention<<"   "<< m;
    if(name.isEmpty()){

        name="Sample";
        int i=1;
        if (this->output.exists(path+name+".html")) {
            while (this->output.exists(path+name+"("+QString::number(i)+")"+".html")) {
                i++;
            }
            name = path+name+"("+QString::number(i)+")"+".html";
        }
        else {
            name = path+name+".html";
        }
    }
    else{
        QString extention;
        int m=name.indexOf(".");
        int n=name.length();
        extention=name.right(n-m-1);
        name=name.left(m);
        int i=1;
        qDebug() <<extention;
        if (extention.isEmpty() || m==-1) {
            if (this->output.exists(path+name+".html")) {
                while (this->output.exists(path+name+"("+QString::number(i)+")"+".html")) {
                    i++;
                }
                name = path+name+"("+QString::number(i)+")"+".html";
            }
            else {
                name = path+name+".html";
            }
        }
        else { 
            if (this->output.exists(path+name+"."+extention)) {
                while (this->output.exists(path+name+"("+QString::number(i)+")"+"."+extention)) {
                    i++;
                }
                name = this->path+name+"("+QString::number(i)+")"+"."+extention;
            }
            else {
                name = this->path+name+"."+extention;
            }
        }


    }

    this->output.setFileName(name);




    if (!output.open(QIODevice::WriteOnly)) {
        fprintf(stderr, "Problem opening save file '%s' for download '%s': %s\n",
                qPrintable(name), url.toEncoded().constData(),
                qPrintable(output.errorString()));
        Error = "Problem opening save file '" + name+"' for download '"+url.toEncoded().constData()+"': "+qPrintable(output.errorString())+"\n";
        emit finished();
        return;                 // skip this download
    }

    output.remove();
    output.close();
    QNetworkRequest request(url);

    currentDownload = manager.get(request);
    currentDownload->setReadBufferSize(100);
    connect(currentDownload, SIGNAL(downloadProgress(qint64,qint64)),
            SLOT(downloadProgress(qint64,qint64)));
    connect(currentDownload, SIGNAL(finished()),
            SLOT(downloadFinished()));
    connect(currentDownload, SIGNAL(finished()),
            SLOT(downloadReadyRead()));
//    connect(currentDownload, SIGNAL(readyRead()),
//            SLOT(downloadReadyRead()));

    // prepare the output
    printf("Downloading %s...\n", url.toEncoded().constData());
    downloadTime.start();


//system("PAUSE");


//        output.write("abc");
//        output.close();





//    output.setFileName("hi.txt");
//    if (!output.open(QIODevice::WriteOnly)) {
//        fprintf(stderr, "Problem opening save file '%s' for download '%s': %s\n",
//                qPrintable("hi.txt"), url.toEncoded().constData(),
//                qPrintable(output.errorString()));

//        return;                 // skip this download
//    }
//    output.write("abc");
//    output.close();
}








