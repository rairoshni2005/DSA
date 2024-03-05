#include <iostream>
using namespace std;

int main() {
    //--------------------array declaration----------------------//
    int array[6]; 

    //-----------------------initializing------------------------//
    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    array[3] = 4;
    array[4] = 5;

    //------------2-------array element access--------------------//
    cout << "Elements of the array:" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;

    //-------------------Insertion at the beginning---------------------//
    int newValue = 0;
    for (int i = 5; i > 0; --i) {
        array[i] = array[i - 1];
    }
    array[0] = newValue;

    //-------------------Insertion at the end------------------------//
    newValue = 6;
    array[5] = newValue;

    //----------------Insertion at any given index---------------------//
    int index = 3;
    newValue = 99;
    for (int i = 5; i > index; --i) {
        array[i] = array[i - 1];
    }
    array[index] = newValue;

    // Update size accordingly
    int size = 6;

    // Printing the array after insertion
    cout << "Elements of the array after insertion:" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;


    //-------------------Deletion at any given index---------------------//
    int indexToDelete = 2;
    for (int i = indexToDelete; i < 5; ++i) {
        array[i] = array[i + 1];
    }

    // Update size accordingly
    //int size = 5;

    // Printing the array after deletion
    cout << "Elements of the array after deletion:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}
