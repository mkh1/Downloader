#include "class_downloader.h"

#include <QFileInfo>


//constructor
Class_downloader::Class_downloader(QUrl url)
{
    this->url=url;
}

Class_downloader::Class_downloader(QString url)
{
    this->url.setUrl(QString(QUrl::toPercentEncoding(url, "/:")));
}





void Class_downloader::Set_Name_Save_File_default()
{
    QString path = this->url.path();
    QString basename = QFileInfo(path).fileName();
}




