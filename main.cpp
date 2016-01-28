#include "mainwindow.h"
#include <QApplication>
#include "node.h"
#include "listasimples.h"
#include "carta.h"
#include <iostream>
#include "jogador.h"
using namespace std;


int main(int argc, char *argv[])
{

    /*ListaSimples *teste = new ListaSimples();
    teste->addNode(11,"paus");
    teste->addNode(12,"paus");
    teste->addNode(13,"paus");
    teste->displayList();
    teste->releaseNode(12,"paus");
    teste->displayList();
    teste->releaseNode(12,"paus");
    teste->displayList();
    teste->releaseNode(13,"paus");
    teste->displayList();*/

    /*Carta *teste = new Carta();
    ListaSimples *Joao      = new ListaSimples();
    ListaSimples *Carol     = new ListaSimples();
    ListaSimples *Ana       = new ListaSimples();
    ListaSimples *Beto      = new ListaSimples();
    ListaSimples *Fila1  	= new ListaSimples();
    ListaSimples *Fila2		= new ListaSimples();
    ListaSimples *Fila3 	= new ListaSimples();
    ListaSimples *Fila4 	= new ListaSimples();*/

    /*teste->setBaralho();
    cout << "Antes de embaralhar..." << endl;
    teste->mostrarBaralho();
    cout << "Embaralhando..." << endl;
    teste->setEmbaralhar();
    teste->mostrarBaralho();

    teste->distribuirCartas(Joao,4);
    cout << "Cartas de Joao" << endl;
    Joao->displayList();
    cout << "Cartas de Carol" << endl;
    teste->distribuirCartas(Carol,4);
    Carol->displayList();
    cout << "Cartas de Ana" << endl;
    teste->distribuirCartas(Ana,4);
    Ana->displayList();
    cout << "Cartas de Beto" << endl;
    teste->distribuirCartas(Beto,4);
    Beto->displayList();
    cout << "Cartas que restam" << endl;
    teste->mostrarBaralho();

    teste->distribuirCartas(Fila1,2);
    cout << "Cartas de Fila 1" << endl;
    Fila1->displayList();
    cout << "Cartas de Fila 2" << endl;
    teste->distribuirCartas(Fila2,2);
    Fila2->displayList();
    cout << "Cartas de Fila 3" << endl;
    teste->distribuirCartas(Fila3,2);
    Fila3->displayList();
    cout << "Cartas de Fila 4" << endl;
    teste->distribuirCartas(Fila4,2);
    Fila4->displayList();
    cout << "Cartas que restam" << endl;
    teste->mostrarBaralho();*/



    Carta *baralho = new Carta();
    int maoDe = 4;
    Jogador *Joao = new Jogador("Joao",maoDe);
    baralho->setBaralho();
    baralho->setEmbaralhar();
    Joao->maoJogador(baralho);
    Joao->mostrarMao();




    //QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    //return a.exec();
}
