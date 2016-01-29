#ifndef JOGADOR
#define JOGADOR
#include "listasimples.h"
#include "carta.h"
#include <QtCore>
class Jogador : public QThread
{
    public:
        Jogador(QString,int,int,int);
        Jogador();

        void maoJogador(Carta *);
        void descartarCarta(ListaSimples*);
        void puxarCarta(ListaSimples*);
        void mostrarMao();
        void verificarSeGanhou();
        void puxarCartaF(int);
        void descartarCartaF(int);
        void run();

        int verficarMao();
        int getQtdJogadas();
        Node *getCarta();
        static bool fimDoJogo;
        static bool getFim();
        //Filas Compartilhadas

        static ListaSimples *Fila1;
        static ListaSimples *Fila2;
        static ListaSimples *Fila3;
        static ListaSimples *Fila4;

    private:
        QString nomeJogador;
        ListaSimples *mao;
        int qtdDeJogadas;
        int tamanhoDaMao;
        int tamanhoDaFila;
        int id;
       // int qtdDeCartas;



};



#endif // JOGADOR

