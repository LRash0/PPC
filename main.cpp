#include "mainwindow.h"
#include <QApplication>
#include "node.h"
#include "listasimples.h"
#include "carta.h"
#include <iostream>
#include "jogador.h"
#include <cstdio>
#include <cstdlib>
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
    */

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


    int maoDe = 4;
    int tamanhoDaFila = 2;
    Carta *baralho = new Carta();

    Jogador *Joao   = new Jogador("Joao",maoDe,tamanhoDaFila,1);
    Jogador *Carol  = new Jogador("Carol",maoDe,tamanhoDaFila,2);
    Jogador *Ana    = new Jogador("Ana",maoDe,tamanhoDaFila,3);
    Jogador *Beto   = new Jogador("Beto",maoDe,tamanhoDaFila,4);
    Jogador *ManipulaFila = new Jogador();

    /*ListaSimples *Fila1 = new ListaSimples();
    ListaSimples *Fila2	= new ListaSimples();
    ListaSimples *Fila3 = new ListaSimples();
    ListaSimples *Fila4 = new ListaSimples();*/

    //Criando o baralho e embaralhando
    baralho->setBaralho();
    baralho->setEmbaralhar();
    //Distribuindo as cartas entre os jogadores
    //--------------------------------------------------Joao
    Joao->maoJogador(baralho);
    Joao->mostrarMao();
    cout << endl << endl << endl;
    baralho->mostrarBaralho();
    //--------------------------------------------------Carol
    Carol->maoJogador(baralho);
    Carol->mostrarMao();
    cout << endl << endl << endl;
    baralho->mostrarBaralho();
    //--------------------------------------------------Ana
    Ana->maoJogador(baralho);
    Ana->mostrarMao();
    cout << endl << endl << endl;
    //--------------------------------------------------Beto
    baralho->mostrarBaralho();
    Beto->maoJogador(baralho);
    Beto->mostrarMao();
    cout << endl << endl << endl;

//    baralho->mostrarBaralho();
//    cout << endl;
    //Inicializando as filas
    baralho->distribuirCartas(ManipulaFila->Fila1,tamanhoDaFila);
//    cout << "Fila 1 " << endl;
//    ManipulaFila->Fila1->displayList();
//    cout << endl << endl << endl;
    baralho->distribuirCartas(ManipulaFila->Fila2,tamanhoDaFila);
//    cout << "Fila 2 " << endl;
//    ManipulaFila->Fila2->displayList();
//    cout << endl << endl << endl;
    baralho->distribuirCartas(ManipulaFila->Fila3,tamanhoDaFila);
//    cout << "Fila 3 " << endl;
//    ManipulaFila->Fila3->displayList();
//    cout << endl << endl << endl;
    baralho->distribuirCartas(ManipulaFila->Fila4,tamanhoDaFila);
//    cout << "Fila 4 " << endl;
//    ManipulaFila->Fila4->displayList();
//    cout << endl << endl << endl;
//    baralho->mostrarBaralho();




    /*while(!(Jogador::getFim())){

    Joao->puxarCarta(Fila4);
//    Joao->mostrarMao();
    //getchar();getchar();

    Carol->puxarCarta(Fila1);
//    Carol->mostrarMao();
   // getchar();getchar();

    Ana->puxarCarta(Fila2);
//    Ana->mostrarMao();
    //getchar();getchar();

    Beto->puxarCarta(Fila3);
//    Beto->mostrarMao();
    //getchar();getchar();

    Joao->descartarCarta(Fila1);
//    Joao->mostrarMao();
    //getchar();getchar();

    Carol->descartarCarta(Fila2);
//    Carol->mostrarMao();
    //getchar();getchar();


    Ana->descartarCarta(Fila3);
//    Ana->mostrarMao();
    //getchar();getchar();


    Beto->descartarCarta(Fila4);
//    Beto->mostrarMao();
    //getchar();getchar();

}


    cout << Joao->getQtdJogadas() << endl;
    cout << Carol->getQtdJogadas() << endl;
    cout << Ana->getQtdJogadas() << endl;
    cout << Beto->getQtdJogadas() << endl;*/

    while(!(Joao->getFim())){
        Joao->start();
        Carol->start();
        Ana->start();
        Beto->start();
    }


    qDebug("saiu");

    cout << Joao->getQtdJogadas() << endl;
    cout << Carol->getQtdJogadas() << endl;
    cout << Ana->getQtdJogadas() << endl;
    cout << Beto->getQtdJogadas() << endl;

    //QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    //return a.exec();
}
