#include <QCoreApplication>
//#include "downloader_class.h"
#include <class_downloader.h>

int main(int argc, char *argv[])
{QCoreApplication a(argc, argv);

    Class_downloader a1("http://www.pdf995.com/samples/pdf.pdf");
//    https://www.tldp.org/HOWTO/pdf/SSL-Certificates-HOWTO.pdf
//    http://www.pdf995.com/samples/pdf.pdf




    return a.exec();
}
