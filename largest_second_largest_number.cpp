#include <iostream>
using namespace std;
int main() {
    const int n = 4;
    int marks[n];
    cout << "Enter marks of 4 students:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Student " << i + 1 << ": ";
        cin >> marks[i];
    }
    int firstTopper = -1, secondTopper = -1;

    for (int i = 0; i < n; ++i) {
        if (marks[i] > firstTopper) {
            secondTopper = firstTopper;
            firstTopper = marks[i];
        } else if (marks[i] > secondTopper && marks[i] < firstTopper) {
            secondTopper = marks[i];
        }
    }
    cout << "1st Topper: Student with marks " << firstTopper << endl;
    cout << "2nd Topper: Student with marks " << secondTopper << endl;
    return 0;
}