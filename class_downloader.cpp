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
    this->url.setUrl(QString(QUrl::toPercentEncoding(url, "/:")));
}

void Class_downloader::Start_Download()
{
    this->path="";
    Set_Output_default();
}

void Class_downloader::Set_Name_File(QString name)
{
    this->file_name=name;
}
void Class_downloader::Set_Path_File(QString path){
    this->file_path=path;
}

void Class_downloader::Init()
{
    this->Set_Name_File("Sample");
    this->Set_Path_File("");
}




void Class_downloader::Set_Output_default()
{
    QString path = this->url.path();
    QString basename = QFileInfo(path).fileName();
    Set_Output("",basename);

}

void Class_downloader::Set_Output(QString path, QString name)
{
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

            return;                 // skip this download
        }
        output.write("abc");
        output.close();





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






