#include <QLocale>
#include <QString>
#include <QTranslator>
#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTranslator appTranslator;
    appTranslator.load("fractions_" + QLocale::system().name(),
                       ":/translations");
    app.installTranslator(&appTranslator);
    MainWindow w;
    w.show();
    return app.exec();
}
