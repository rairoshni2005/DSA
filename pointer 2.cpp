#include <iostream>
using namespace std;
int main(){
    ///int *ptr,p;///
    // int a=5;
    // int *ptr;
    // ptr=&a;
    // //a=7;
    // *ptr=7;
    // cout<<"The size pf pointer here is"<<sizeof(a)<<endl;
    // cout<<"The size pf pointer here is"<<sizeof(ptr)<<endl;
    // cout<<a<<endl;
    // cout<<*ptr;

//without bracket increment decrement nahi hoga

    int a=5;
    int b=6;
    int *ptr1=&a;
    int *ptr2=&b;

    //addition
    int sum = *ptr1 + *ptr2;
    cout<<sum<<endl;

    //increment
   (*ptr1)++;
   (*ptr1)--;
   cout<<a<<endl;
   cout<<b<<endl;
}