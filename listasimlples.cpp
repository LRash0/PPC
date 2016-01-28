#include "listasimples.h"
#include <iostream>

ListaSimples::ListaSimples()
{
    first = NULL;
    count = 0;
}

ListaSimples::~ListaSimples()
{
    Node * tmp; //Nó temporário
    tmp = first;

    while(tmp!=NULL){

        first = first->next;
        delete tmp;
        tmp = first;

    }
}

bool ListaSimples::isEmpty()
{

    return (first==NULL);
}

void ListaSimples::addNode(int data,QString suit)
{

    if(isEmpty()){

        first = new Node(data,suit);


    }else{

        Node *tmp = new Node(data,suit);
        Node *last = first;

        while(last->next!=NULL){

            last = last->next;

        }

        last->next = tmp;


    }
    ++count;

}

void ListaSimples::displayList()
{
    Node *tmp = first;

    if(isEmpty()){
        std::cout << "LISTA ESTA VAZIA" << std::endl;
    }else{

        while(tmp!=NULL){

            /*std::cout << "Dado: "   << tmp->data
                      << std::endl;
            std::cout <<   "Naipe: "  << tmp->suit.toStdString()
                      << std::endl;*/
            std::cout << tmp->data << tmp->suit.toStdString()
                      <<   std::endl;

            tmp = tmp->next;
        }

    }
}

//Apaga um nó especifico na lista
void ListaSimples::releaseNode(int data,QString suit)
{
    if(isEmpty()){
        //Fazer nada

    }else{
        Node * tmp = first;
        Node *prev = NULL;
        bool isFirst = (tmp->data==data) && (tmp->suit==suit);


        if(isFirst){
            first = first->next;
            delete tmp;

        //Senão for no o primeiro,procurar no restante da fila
        }else{

            prev = tmp;
            tmp = tmp->next;

            while(tmp!=NULL){

                if(tmp->data==data){

                    if(tmp->suit==suit){
                        break;
                    }//Sai do laço se achar o valor

                }

                //Se não achar,vai para o próximo

                prev = tmp;
                tmp = tmp->next;
            }

            prev->next = tmp->next;
            delete tmp;

        }

        --count;

    }//Fim do else

}


int ListaSimples::getCount()
{
    return count;
}

Node *ListaSimples::walkQueue(int walking)
{
    Node *tmp = first;

    for (int var = 0; var < walking; ++var) {
        tmp = tmp -> next;
    }

    return tmp;

}

Node *ListaSimples::getFirst()
{
    return first;
}

void ListaSimples::deleteAmountOfCards(int amount)
{
    Node *tmp = first;
    for(int i = 0 ; i < amount ; ++i){
        first = first->next;
        delete tmp;
        tmp = first;
    }
}
