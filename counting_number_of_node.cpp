#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node * next;
};

Node* insert(int value){
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int main(){
    Node * start;
    Node *n1 = insert(30);
    start = n1;

    Node *n2 = insert(40);
    n1->next = n2;

    Node *n3 = insert(50);
    n2->next = n3;

    Node *n4 = insert(60);
    n3->next = n4;

    Node *n5 = insert(70);
    n4->next = n5;

    Node * ptr = start;
    int count = 0;
    while(ptr != NULL){
        count++;
        ptr = ptr->next;
    }
    cout << "Total number of nodes present - "<<count << endl;
    
    return 0;
}