#include "class_downloader.h"

#include <QFileInfo>
#include <QString>
#include <QNetworkReply>


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
    this->speed=QString::number(speed)+unit;
}

void Class_downloader::downloadFinished()
{
    output.close();

    if (currentDownload->error()) {
        // download failed
        fprintf(stderr, "Failed: %s\n", qPrintable(currentDownload->errorString()));
    } else {
        printf("Succeeded.\n");
    }
//    emit finished();
}

void Class_downloader::downloadReadyRead()
{
    this->output.write(currentDownload->readAll());
}

void Class_downloader::Init()
{
    qDebug() << "gg";
//    setSpeed(600);
    qDebug() << "gg";
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
    qDebug() << "gg";
    if(name.isEmpty()){
        qDebug() << "gg";
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
        int i=name.indexOf(".");
        int j=name.length();
        extention=name.right(j-i-1);
        name=name.left(i);
        if (extention.isEmpty() || extention==name) {
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

    QNetworkRequest request(url);

    currentDownload = manager.get(request);
    currentDownload->setReadBufferSize(1);
    connect(currentDownload, SIGNAL(downloadProgress(qint64,qint64)),
            SLOT(downloadProgress(qint64,qint64)));
    connect(currentDownload, SIGNAL(finished()),
            SLOT(downloadFinished()));
    connect(currentDownload, SIGNAL(readyRead()),
            SLOT(downloadReadyRead()));

    // prepare the output
    printf("Downloading %s...\n", url.toEncoded().constData());
    downloadTime.start();

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







