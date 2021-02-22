#include "mainwindow.h"

#include <QApplication>
#include <QFontDatabase>
#include <QDebug>
#include <QStyleFactory>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QApplication::setStyle("Fusion");

    QFontDatabase::addApplicationFont(":/fonts/MonoFont");

    MainWindow w;
    w.show();
    return QApplication::exec();
}
