#include "DRThemeEditor.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DR::DRThemeEditor w;
    w.show();
    return a.exec();
}
