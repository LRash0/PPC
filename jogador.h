#ifndef JOGADOR
#define JOGADOR
#include "listasimples.h"
#include "carta.h"

class Jogador
{
    public:
        Jogador(QString,int,int);

        void maoJogador(Carta *);
        void descartarCarta(ListaSimples*);
        void puxarCarta(ListaSimples*);
        void mostrarMao();
        void verificarSeGanhou();

        int verficarMao();
        int getQtdJogadas();
        Node *getCarta();
        static bool fimDoJogo;
        static bool getFim();

    private:
        QString nomeJogador;
        ListaSimples *mao;
        int qtdDeJogadas;
        int tamanhoDaMao;
        int tamanhoDaFila;
       // int qtdDeCartas;



};



#endif // JOGADOR

