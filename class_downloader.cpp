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
    QString path = this->url.path();
    QString basename = QFileInfo(path).fileName();
    basename="mymusic.i";
    if(basename.isEmpty()){
        basename="Sample";
        int i=0;
        if (QFile::exists(basename+".html")) {
            while (QFile::exists(basename+"("+QString::number(i)+")"+".html")) {
                i++;
            }
            basename = basename+"("+QString::number(i)+")"+".html";
        }
        else if (QFile::exists(basename)) {
            while (QFile::exists(basename+"("+QString::number(i)+")")) {
                i++;
            }
            basename = basename+"("+QString::number(i)+")";
        }
    }
    else{
        QString extention;
        int i=basename.indexOf(".");
        int j=basename.length();
        extention=basename.right(j-i-1);
        basename=basename.left(i);
        if (extention.isEmpty() || extention==basename) {

            qDebug() << basename<<"  "<<extention;
        }
        else {

        }


    }






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




