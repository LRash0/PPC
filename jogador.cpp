#include "jogador.h"

Jogador::Jogador(QString nomeJogador,int tamanhoDaMao)
{
    this->nomeJogador = nomeJogador;
    this->tamanhoDaMao = tamanhoDaMao;
    qtdDeJogadas = 0;
    mao = new ListaSimples();


}

void Jogador::maoJogador(Carta *baralho)
{
    baralho->distribuirCartas(this->mao,tamanhoDaMao);
}

void Jogador::mostrarMao()
{
    mao->displayList();
}

void Jogador::puxarCarta(ListaSimples *filaAtual)
{

}

void Jogador::descartarCarta(ListaSimples *filaAtual)
{

}
