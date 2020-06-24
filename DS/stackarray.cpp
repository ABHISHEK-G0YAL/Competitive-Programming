#include<iostream>
using namespace std;
#define MAX_SIZE 101
int A[MAX_SIZE];
int top=-1;
void push(int x)
{
    if(top==MAX_SIZE-1)
    {
        cout<<"stack overflow"<<endl;
    }
    else
    {
        top++;
        A[top]=x;
    }
}
void pop()
{
    if(top==-1)
    {
        cout<<"stack empty"<<endl;
    }
    else
    {
        top--;
    }

}
void print()
{
    cout<<"the element at top is ";
    cout<<A[top]<<endl;

}
int main()
{
    push(10);
    push(20);
    print();
    push(39);
    push(67);
    push(27);
    print();
    pop();
    print();
    return 0;
}
