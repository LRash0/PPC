#ifndef CARTA
#define CARTA
#include "listasimples.h"
#include "node.h"
class Carta
{

    public:
        Carta();
        ~Carta();

    void setBaralho();
    void setDistribuirCarta();
    void setEmbaralhar();
    void setCriarCartas(int,int,int);
    void mostrarBaralho();
    void distribuirCartas(ListaSimples*,int);



    private:

    ListaSimples *baralho;
    int tamanhoBaralho;


};


#endif // CARTA

