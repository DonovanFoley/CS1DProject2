/*#include "stadiummanager.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StadiumManager w;
    w.show();
    return a.exec();
}*/

#include <QApplication>
#include <QWidget>
#include "stadiummanager.h"
#include "graph.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget mainWindow;

    StadiumManager stadiumManager;
    stadiumManager.loadStadiums();
    stadiumManager.performDFS(&mainWindow);
    stadiumManager.performBFS(&mainWindow);

    return app.exec();
}
