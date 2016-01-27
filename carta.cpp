#include "carta.h"

Carta::Carta()
{
    baralho = new ListaSimples();
    setBaralho();
    tamanhoBaralho = 24;
}

Carta::~Carta()
{
    delete []baralho;
}

//Exibi o baralho
void Carta::mostrarBaralho()
{
    baralho->displayList();
}

//Criando o baralho
void Carta::setBaralho()
{
    QString naipe[] = {"O","C","E","P"}; // O = Ouro, C = Copas, E = Espadas, P = Paus;
    int numero = 1;
    int qtdNaipe = 4;


    //Criando o baralho
    while(numero<7){

        for(int i = 0 ; i < qtdNaipe ; ++i ){

            baralho->addNode(numero,naipe[i]);
        }

        ++numero;
    }

} //Fim da função
