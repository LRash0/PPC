#ifndef NODE
#define NODE
#include <QString>
class Node
{

    public:

         Node(int,QString);


        int data;
        QString suit;
        Node *next;//aponta para o próximo na lista
};


#endif // NODE

