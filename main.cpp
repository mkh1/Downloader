#include <QCoreApplication>
//#include "downloader_class.h"
#include <class_downloader.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Class_downloader a1;

    a1.Start_Download();

    return a.exec();
}
