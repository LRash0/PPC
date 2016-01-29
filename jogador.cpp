#include "jogador.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
using namespace std;

//Inicializando variáveis static
bool Jogador::fimDoJogo = false;
ListaSimples *Jogador::Fila1 = new ListaSimples();
ListaSimples *Jogador::Fila2 = new ListaSimples();
ListaSimples *Jogador::Fila3 = new ListaSimples();
ListaSimples *Jogador::Fila4 = new ListaSimples();

bool Jogador::getFim()
{
    return fimDoJogo;
}


Jogador::Jogador()
{

}

Jogador::Jogador(QString nomeJogador,int tamanhoDaMao,int tamanhoDaFila,int id)
{
    this->nomeJogador = nomeJogador;
    this->tamanhoDaMao = tamanhoDaMao;
    this->tamanhoDaFila = tamanhoDaFila;
    this->id = id;
    qtdDeJogadas = 0;
    mao = new ListaSimples();


}

void Jogador::maoJogador(Carta *baralho)
{
    baralho->distribuirCartas(this->mao,tamanhoDaMao);

}

void Jogador::mostrarMao()
{
    cout << "Mao de:" << this->nomeJogador.toStdString() << endl;
    mao->displayList();
    cout << endl;
//    cout << "Max:" << this->verficarMao() << endl;
//    getchar();
}

void Jogador::puxarCarta(ListaSimples *filaAtual)
{
    int qtdDeItens = filaAtual->getCount();
    int qtdDeCartas = this->mao->getCount();
    //Não permiti jogador atual puxar carta se: a fila tiver apenas uma carta
    //Ou a quantidade de cartas na sua mao for maior que 4
    if(qtdDeItens < tamanhoDaFila || qtdDeCartas > tamanhoDaMao){

        cout << "Não pode puxar" << endl;

    }else{
        //Obtem a primeira carta da fila atual
        Node *tmp = filaAtual->getFirst();
        //Insere na mao do jogador atual
        this->mao->addNode(tmp->data,tmp->suit);
        //Remove a carta da fila
        filaAtual->releaseNode(tmp->data,tmp->suit);
        ++qtdDeJogadas;
    }

}

void Jogador::descartarCarta(ListaSimples *filaAtual)
{
    int qtdDeItens = filaAtual->getCount();
//    int qtdDeCartas = this->mao->getCount();

    if((qtdDeItens == tamanhoDaFila)){
        cout << "Não pode descartar!!" << endl;
    }else{
        Node *tmp = this->getCarta();
        filaAtual->addNode(tmp->data,tmp->suit);
        this->mao->releaseNode(tmp->data,tmp->suit);
        ++qtdDeJogadas;
    }

    this->verificarSeGanhou();

}

int Jogador::verficarMao()
{
    //Contando a partir de 1 até 6.Como vetor começa com 0,criar um vetor de 7 posições
    int qtdCartas[7] = {0};
    Node *tmp = mao->getFirst();
    int max = 0;


    while(tmp!=NULL){

        if(tmp->data==1){

            ++qtdCartas[1];
        }

        if(tmp->data==2){

            ++qtdCartas[2];
        }

        if(tmp->data==3){

            ++qtdCartas[3];
        }

        if(tmp->data==4){

            ++qtdCartas[4];
        }

        if(tmp->data==5){

            ++qtdCartas[5];
        }

        if(tmp->data==6){

            ++qtdCartas[6];
        }


        tmp = tmp->next;

    }

    max = qtdCartas[1];

    for(int i = 2 ; i < 7;++i){
        if(qtdCartas[i]>max){
            max = qtdCartas[i];
        }
    }

    return max;

}

Node *Jogador::getCarta()
{
    srand((int)time(0));

    int aleatorio = rand() % (tamanhoDaMao + 1);
//    cout << aleatorio << endl;
//    getchar();
    Node *tmp = this->mao->walkQueue(aleatorio);

    return tmp;

}

void Jogador::verificarSeGanhou()
{
    //Verifica se alguem ganhou
    int fim = this->verficarMao();
    if((fim==4)){
        Jogador::fimDoJogo = true;
        cout << "Ganhou!!!!" << endl;
        cout << this->nomeJogador.toStdString() << endl;
        this->mostrarMao();
        getchar();
    }

}

int Jogador::getQtdJogadas()
{
    return qtdDeJogadas;
}


void Jogador::run()
{

}
