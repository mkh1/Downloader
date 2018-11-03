#include "class_downloader.h"

Class_downloader::Class_downloader(QUrl url)
{
    this->url=url;
}

Class_downloader::Class_downloader(QString url)
{
    this->url.setUrl(QString(QUrl::toPercentEncoding(url, "/:")));
}


