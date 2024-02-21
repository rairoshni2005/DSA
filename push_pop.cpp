#include <iostream>
using namespace std;

const int n = 100;



class Stack{
    public:
    int * arr;
    int top;

    public:
    Stack(){
        arr = new int[n];
        top = -1;
    }
    void push(int x)
    {
        if(top == n-1){
        cout<<"Stack overflow"<<endl;
        }
        else{
        top++;
        arr[top] = x;
        }
    }

    void pop(){
        if(top == -1)
        {
            cout<<"No element to pop";
            return;
        }
        top--;
    }

    int  Tope()
    {
        if(top == -1)
        {
            cout<<"No element in the stack";
            return -1;
        }
        return arr[top];
    }
    bool empty()
    {
        return top == -1;
    }

    void Print()
    {
        for(int i =0;i<n;i++)
        {
            cout<<arr[i]<<",";
        }
    }


};
int main()
{

    Stack st;
    st.push(1);
    st.push(3);
    st.push(4);
    st.pop();
    st.pop();
    st.pop();
    st.empty();
    return 0;
}