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
            std::cout << tmp->data << tmp->suit.toStdString();
            tmp = tmp->next;
        }

    }
}

void ListaSimples::releaseNode(int data,QString suit)
{
    if(!(isEmpty())){
        Node *tmp = first;
        Node *prev = NULL;
        bool isFirst = ((tmp->data == data) && (tmp->suit == suit) );

        if(isFirst){

            first = first->next;
            delete tmp;


        }else{

            prev = tmp;
            tmp = tmp->next;
            //Criar uma função membro para essa parte do laço
            while( (tmp->data!=data) && (tmp->suit!=suit) ){
                prev = tmp;
                tmp = tmp->next;
            }

            prev->next = tmp->next;
            delete tmp;
        }

    }

    --count;

}
