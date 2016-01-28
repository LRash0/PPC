#ifndef JOGADOR
#define JOGADOR
#include "listasimples.h"
#include "carta.h"

class Jogador
{
    public:
        Jogador(QString,int);

        void maoJogador(Carta *);
        void descartarCarta(ListaSimples*);
        void puxarCarta(ListaSimples*);
        void mostrarMao();
        static bool fimDoJogo;

    private:
        QString nomeJogador;
        ListaSimples *mao;
        int qtdDeJogadas;
        int tamanhoDaMao;



};



#endif // JOGADOR

