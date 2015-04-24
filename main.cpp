#include "trinity.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Trinity w;
    w.show();

    return a.exec();
}
