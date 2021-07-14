#include <QApplication>
#include "App/app.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    App w;
    w.run();
    return a.exec();
}
