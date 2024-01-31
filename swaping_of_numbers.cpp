#include <iostream>
using namespace std;

int findLargeindex(int arr[], int size) {
    int largeindex = 0;
    for (int i = 1; i < size; ++i) {
        if (arr[i] > arr[largeindex]) {
            largeindex = i;
        }
    }
    return largeindex;
}
int findSmallindex(int arr[], int size) {
    int smallindex = 0;
    for (int i = 1; i < size; ++i) {
        if (arr[i] < arr[smallindex]) {
            smallindex = i;
        }
    }
    return smallindex;
}
void swapValues(int arr[], int size) {
    int largeindex = findLargeindex(arr, size);
    int smallindex = findSmallindex(arr, size);
    int temp = arr[largeindex];
    arr[largeindex] = arr[smallindex];
    arr[smallindex] = temp;
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
    const int size = 5; 
    int numbers[size];
    cout << "Enter " << size << " numbers: ";
    for (int i = 0; i < size; ++i) {
        cin >> numbers[i];
    }
    cout << "Original Array: ";
    printArray(numbers, size);
    swapValues(numbers, size);
    cout << "Array after swapping largest and smallest elements: ";
    printArray(numbers, size);
    return 0;
}