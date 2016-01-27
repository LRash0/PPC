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
    void setCriarCarta();
    void mostrarBaralho();

    private:

    ListaSimples *baralho;
    int tamanhoBaralho;


};


#endif // CARTA

