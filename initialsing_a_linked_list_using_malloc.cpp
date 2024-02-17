#include <iostream>
#include <cstdlib> 
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

int main() {
    Node* start;
    Node* n1 = (Node*)malloc(sizeof(Node)); 
    start = n1;
    n1->data = 30;
    n1->next = NULL;

    Node* n2 = (Node*)malloc(sizeof(Node)); 
    n1->next = n2;
    n2->data = 40;
    n2->next = NULL;

    Node* n3 = (Node*)malloc(sizeof(Node));
    n2->next = n3;
    n3->data = 50;
    n3->next = NULL;

    cout << n1->data << endl << n2->data << endl << n3->data << endl;

    free(n1);
    free(n2);
    free(n3);

    return 0;
}
