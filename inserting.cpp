#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

int main() { 
    Node* start;
    
    Node* n1 = new Node;
    start = n1;
    n1->data = 30;
    n1->next = NULL;

    Node* n2 = new Node;
    n1->next = n2;
    n2->data = 40;
    n2->next = NULL;

    Node* n3 = new Node;
    n2->next = n3;
    n3->data = 50;
    n3->next = NULL;

    Node* n4 = new Node;
    n3->next = n4;
    n4->data = 60;
    n4->next = NULL;

    Node* n5 = new Node;  
    Node* current = start;

    if (n5 == NULL) {
        cout << "Overflow" << endl;
    } else {
        n5->data = 70;
        n5->next = start;
        start = n5;
    }

    
    current = start;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}