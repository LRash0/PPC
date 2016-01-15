#ifndef LISTASIMPLES
#define LISTASIMPLES
#include "node.h"
class ListaSimples
{
    public:
         ListaSimples();
         ListaSimples(int,QString);
        ~ListaSimples();

        //Adiconar,Remover,Buscar
        void addNode(int,QString);
        void searchNode(int);
        void releaseNode(int, QString);
        void displayList();

        Node *getFirst();

        bool isEmpty();

    private:
        Node *first;
        int count;

};

#endif // LISTASIMPLES

