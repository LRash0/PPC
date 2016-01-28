#include "mainwindow.h"
#include <QApplication>
#include "node.h"
#include "listasimples.h"
#include "carta.h"
#include <iostream>
using namespace std;


int main(int argc, char *argv[])
{

    ListaSimples *teste = new ListaSimples();
    teste->addNode(11,"paus");
    teste->addNode(12,"paus");
    teste->addNode(13,"paus");
    teste->displayList();
    teste->releaseNode(13,"paus");
    teste->displayList();
    /*teste->releaseNode(12,"paus");
    teste->displayList();
    teste->releaseNode(13,"paus");
    teste->displayList();

    /*Carta *teste = new Carta();
    teste->setBaralho();
    cout << "Antes de embaralhar..." << endl;
    teste->mostrarBaralho();
    cout << "Embaralhando..." << endl;
    teste->setEmbaralhar();
   // teste->mostrarBaralho();*/





    //QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    //return a.exec();
}
