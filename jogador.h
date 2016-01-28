#ifndef JOGADOR
#define JOGADOR
#include "listasimples.h"
#include "carta.h"

class Jogador
{
    public:
        Jogador();

    private:
        ListaSimples *mao;
        int qtdDeCartas;

};



#endif // JOGADOR

