#include "mainwindow.h"
#include <QApplication>
#include "node.h"
#include "listasimples.h"
int main(int argc, char *argv[])
{

    ListaSimples *teste = new ListaSimples();
    teste->addNode(10,"paus");
    teste->addNode(10,"paus");
    teste->addNode(10,"paus");
    teste->displayList();
    teste->releaseNode(10,"paus");
    teste->displayList();
    teste->releaseNode(10,"paus");
    teste->displayList();
    teste->releaseNode(10,"paus");
    teste->displayList();

    //QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    //return a.exec();
}
