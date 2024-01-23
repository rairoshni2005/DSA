///wap of c++ to calculate passing percentage and failing percentage of students in a given subject
#include <iostream>
using namespace std;

int main() {
    const float totalStudents = 10; 
    int pass = 0, fail = 0;
    float marks, passingNum = 40;

    cout << "Enter marks for " << totalStudents << " students:" << endl;

    for (int i = 0; i < totalStudents; ++i) {
        cout << "Student " << i + 1 << ": ";
        cin >> marks;

        if (marks >= passingNum) {
            pass++;
        } else {
            fail++;
        }
    }
    float passper = (pass / totalStudents) * 100; 
    float failper = (fail / totalStudents) * 100;

    cout << "Passing Percentage: " << passper << "%" << endl;
    cout << "Failing Percentage: " << failper << "%" << endl;
    return 0;
}