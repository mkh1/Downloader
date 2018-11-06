#include "class_downloader.h"

#include <QFileInfo>
#include <QString>


//constructor
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
//    this->url.setUrl(QString(QUrl::toPercentEncoding(url, "/:")));
}

void Class_downloader::Start_Download()
{
    Set_Name_Save_File_default();
}








void Class_downloader::Set_Name_Save_File_default()
{
//    QString path = this->url.path();
//    QString basename = QFileInfo(path).fileName();
//    if(basename.isEmpty()){

//    }
    output.setFileName("hi.txt");
    if (!output.open(QIODevice::WriteOnly)) {
        fprintf(stderr, "Problem opening save file '%s' for download '%s': %s\n",
                qPrintable("hi.txt"), url.toEncoded().constData(),
                qPrintable(output.errorString()));

        return;                 // skip this download
    }
    output.write("abc");
    output.close();

}




