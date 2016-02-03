#include "jogador.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <QMutex>
QMutex mutex14;
QMutex mutex12;
QMutex mutex23;
QMutex mutex34;
QMutex acabou;
QMutex controle;
QMutex verifica;
int qtdCartas[7] = {0};
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
//    qDebug("Erro 8");
    baralho->distribuirCartas(this->mao,tamanhoDaMao);

}

void Jogador::mostrarMao()
{
//    qDebug("Erro 7");
//    controle.lock();
    cout << "Mao de:" << this->nomeJogador.toStdString() << endl;
    mao->displayList();
    cout << endl;
//    cout << "Max:" << this->verficarMao() << endl;
//    getchar();
//    controle.unlock();
}

void Jogador::puxarCarta(ListaSimples *filaAtual)
{
//    qDebug("Erro 6");
    int qtdDeItens = filaAtual->getCount();
    int qtdDeCartas = this->mao->getCount();
    //Não permiti jogador atual puxar carta se: a fila tiver apenas uma carta
    //Ou a quantidade de cartas na sua mao for maior que 4
//    if(qtdDeItens < tamanhoDaFila || qtdDeCartas > tamanhoDaMao){
        if(qtdDeCartas > tamanhoDaMao || filaAtual->isEmpty()){

//        cout << "Não pode puxar" << endl;

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
//    qDebug("Erro 5");
    int qtdDeItens = filaAtual->getCount();
    //    int qtdDeCartas = this->mao->getCount();
    //Verifica se a pilha tem espaço diposnível
    //Se a quantidade de itens da fila for igual ao tamanho,não pode descartar na fila
    if((qtdDeItens == tamanhoDaFila)){
//        cout << "Não pode descartar!!" << endl;

    }else{
        Node *tmp = this->getCarta();
        filaAtual->addNode(tmp->data,tmp->suit);
        this->mao->releaseNode(tmp->data,tmp->suit);
        ++qtdDeJogadas;
         verifica.lock();
         this->verificarSeGanhou();
         verifica.unlock();


    }

    //Verifica se alguém ganhou;
//    verifica.lock();
//    this->verificarSeGanhou();
//    verifica.unlock();


}

int Jogador::verficarMao()
{
    //Contando a partir de 1 até 6.Como vetor começa com 0,criar um vetor de 7 posições
    Node *tmp = mao->getFirst();
    int max = 0;
//    qDebug("Erro 4");
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
//        qDebug("Erro 3");
        if(qtdCartas[i]>max){
            max = qtdCartas[i];
        }
    }

    for(int i = 0 ; i < 7 ; ++i){
        qtdCartas[i] = 0;
//        qDebug("Erro 2");
    }

    return max;

}

Node *Jogador::getCarta()
{
    srand((int)time(0));

    int aleatorio = rand() % (tamanhoDaMao);
//    cout << aleatorio << endl;
//    getchar();
//    qDebug("Erro 1");
    Node *tmp = this->mao->walkQueue(aleatorio);

    return tmp;

}

void Jogador::verificarSeGanhou()
{
    //Verifica se alguem ganhou
    acabou.lock();
    int fim = this->verficarMao();
    if((fim==4)){

        this->fimDoJogo = true;
        cout << "Ganhou!!!!" << endl;
        cout << this->nomeJogador.toStdString() << endl;
        this->mostrarMao();


    }
    acabou.unlock();

}

int Jogador::getQtdJogadas()
{
    return qtdDeJogadas;
}


void Jogador::run()
{

        //mao de 5
        if(this->id==1){
            this->puxarCartaF(this->id);
            this->descartarCartaF(this->id);
        }

        if(this->id==2){
            this->puxarCartaF(this->id);
            this->descartarCartaF(this->id);
        }

        if(this->id==3){
            this->puxarCartaF(this->id);
            this->descartarCartaF(this->id);
        }

        if(this->id==4){
            this->puxarCartaF(this->id);
            this->descartarCartaF(this->id);
        }

        if(!(this->getFim())){
            this->exit();
        }


}

void Jogador::puxarCartaF(int id)
{
    if(id==1){
        if(!(this->getFim())){
        mutex14.lock();
        puxarCarta(Fila4);        
//        Fila4->displayList();
//        this->mostrarMao();
        mutex14.unlock();
        }else{
            this->exit(0);
        }
    }
    if(id==2){
        if(!(this->getFim())){
        mutex12.lock();
        puxarCarta(Fila1);
//        this->mostrarMao();
        mutex12.unlock();
        }else{
            this->exit(0);
        }

    }

    if(id==3){
        if(!(this->getFim())){
        mutex23.lock();
        puxarCarta(Fila2);
//        this->mostrarMao();
        mutex23.unlock();
        }else{
            this->exit(0);
        }
    }

    if(id==4){
        if(!(this->getFim())){
        mutex34.lock();
        puxarCarta(Fila3);
//        this->mostrarMao();
        mutex34.unlock();
        }else{
            this->exit(0);
        }

    }
}

void Jogador::descartarCartaF(int id)
{
    if(id==1){
        if(!(this->getFim())){
        mutex12.lock();
        descartarCarta(Fila1);
//        this->mostrarMao();
        mutex12.unlock();
        }else{
            this->exit(0);
        }

    }

    if(id==2){
        if(!(this->getFim())){
        mutex23.lock();
        descartarCarta(Fila2);
//        this->mostrarMao();
        mutex23.unlock();
        }else{
            this->exit(0);
        }
    }

    if(id==3){
        if(!(this->getFim())){
        mutex34.lock();
        descartarCarta(Fila3);
//        this->mostrarMao();
        mutex34.unlock();
        }else{
            this->exit(0);
        }
    }

    if(id==4){
        if(!(this->getFim())){
        mutex14.lock();
        descartarCarta(Fila4);
//        this->mostrarMao();
        mutex14.unlock();
        }else{
            this->exit(0);
    }
    }
}
