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




    int maoDe = 4;
    int tamanhoDaFila = 2;
    Carta *baralho = new Carta();

    Jogador *Joao   = new Jogador("Joao",maoDe,tamanhoDaFila,1);
    Jogador *Carol  = new Jogador("Carol",maoDe,tamanhoDaFila,2);
    Jogador *Ana    = new Jogador("Ana",maoDe,tamanhoDaFila,3);
    Jogador *Beto   = new Jogador("Beto",maoDe,tamanhoDaFila,4);
    Jogador *ManipulaFila = new Jogador();

    //Criando o baralho e embaralhando
    baralho->setBaralho();
    baralho->setEmbaralhar();
    //Distribuindo as cartas entre os jogadores
    //--------------------------------------------------Joao
    Joao->maoJogador(baralho);
    Joao->mostrarMao();
    cout << endl << endl << endl;
    //--------------------------------------------------Carol
    Carol->maoJogador(baralho);
    Carol->mostrarMao();
    cout << endl << endl << endl;
    //--------------------------------------------------Ana
    Ana->maoJogador(baralho);
    Ana->mostrarMao();
    cout << endl << endl << endl;
    //--------------------------------------------------Beto

    Beto->maoJogador(baralho);
    Beto->mostrarMao();
    cout << endl << endl << endl;

    //Inicializando as filas
    baralho->distribuirCartas(ManipulaFila->Fila1,tamanhoDaFila);
    baralho->distribuirCartas(ManipulaFila->Fila2,tamanhoDaFila);
    baralho->distribuirCartas(ManipulaFila->Fila3,tamanhoDaFila);
    baralho->distribuirCartas(ManipulaFila->Fila4,tamanhoDaFila);





    while(!(Joao->getFim())){
        Joao->start();
        Carol->start();
        Ana->start();
        Beto->start();
    }




    cout <<  Joao->getQtdJogadas() << endl;
    cout << Carol->getQtdJogadas() << endl;
    cout <<  Ana->getQtdJogadas() << endl;
    cout <<  Beto->getQtdJogadas() << endl;

    //QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    //return a.exec();
}
