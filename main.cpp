#include "mainwindow.h"
#include <QApplication>

/**
 * @brief main
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.setWindowTitle("Flipigas"); //Set the main window title as "Flipigas"
    w.move(400,100); //Set the initial position of the main window

    return a.exec();
}
