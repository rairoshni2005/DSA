#include <iostream>
using namespace std;
void insert_begining(int val,int size,int arr[])
{
    for(int i = size+1;i>=0;i--)
    {
        arr[i+1] = arr[i];
    }
    arr[0] = val;
    for(int i = 0;i<size+1;i++)
    {
        cout<<arr[i];
    }
}
int main()
{
    int n;
    cout<<"Enter the size of the array";
    cin>>n;
    int arr[n];
    
    for(int i = 0;i<n;i++)
    {
        cout<<"Enter the elements"<<i+1<<":";
        cin>>arr[i];
    }
    int value;
    cout<<"Enter the value you want to insert";
    cin>>value;
    insert_begining(value,n,arr);
    return 0;
}