#include "carta.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <cstdio>
using namespace std;


Carta::Carta()
{
    baralho = new ListaSimples();
    //setBaralho();
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

void Carta::setBaralho()
{
    int numero = 1;
    int qtdNaipe = 4;
    int qtdDeNumeros = 7;
    setCriarCartas(numero,qtdNaipe,qtdDeNumeros);
}

//Criando o baralho
void Carta::setCriarCartas(int numero,int qtdNaipe,int qtdDeNumero)
{
    QString naipe[] = {"O","C","E","P"}; // O = Ouro, C = Copas, E = Espadas, P = Paus;
//    int numero = 1;
//    int qtdNaipe = 4;


    //Criando o baralho
    while(numero<qtdDeNumero){

        for(int i = 0 ; i < qtdNaipe ; ++i ){

            baralho->addNode(numero,naipe[i]);
        }

        ++numero;
    }

} //Fim da função


void Carta::setEmbaralhar()
{

    ListaSimples *tmp = new ListaSimples();
    Node *aux;
    srand((int)time(0));
    int tamanho = baralho->getCount();
    int aleatorio = 0;
    srand(time(0)); //Para que rand() gere números aléatorios

    //Embaralhando um deck auxiliar
    while(tamanho!=0){

//        cout << "Tamanho: " << tamanho << endl;
        aleatorio = rand() % tamanho;
        aux = baralho->walkQueue(aleatorio);
//        cout << "Carta escolhida: " << aux->data << aux->suit.toStdString() << endl;
        tmp->addNode(aux->data,aux->suit);
//        cout << "Tmp adicionou:" << aux->data << aux->suit.toStdString() << endl;
        baralho->releaseNode(aux->data,aux->suit);
//        baralho->displayList();
        tamanho = baralho->getCount();

    }

    //Depois de embaralhar,colocando no deck original
    aux = tmp->getFirst();
    while(aux!=NULL){

        baralho->addNode(aux->data,aux->suit);
        aux = aux->next;
    }



}

void Carta::distribuirCartas(ListaSimples *cards,int amountOfCards)
{
    Node *tmp = baralho->getFirst();

    for(int i = 0 ; i < amountOfCards ; ++i){
        cards->addNode(tmp->data,tmp->suit);
        tmp = tmp->next;
    }

    baralho->deleteAmountOfCards(amountOfCards);


}
