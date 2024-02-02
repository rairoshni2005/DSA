#include <iostream>
using namespace std;


class Node{
    public:
    int data;
    Node*next;

};

int main()
{
    Node*start;
    Node * n1 = new Node();
    start = n1;
    n1 -> data = 30;
    n1 ->next = NULL; 

    Node*n2 = new Node();
    n1 -> next = n2;
    n2 ->data = 40;
    n2 ->next = NULL;

    Node*n3 = new Node();
    n2 -> next = n3;
    n3 ->data = 40;
    n3 ->next = NULL;

    cout<<n1->data<<endl<<n2 ->data<<endl<<n3 ->data;

    return 0;
}