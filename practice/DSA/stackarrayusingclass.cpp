// 

#include<iostream>
#define MAX_SIZE 101
using namespace std;

class stack {
    int A[MAX_SIZE];
    int top=-1;
    public:
        void push(int x) {
            if(top==MAX_SIZE-1)
                cout<<"stack overflow ,nothing cane be done"<<endl;
            else
                A[++top]=x;
        }
        void pop() {
            if(top==-1)
                cout<<"stack is empty"<<endl;
            else
                top--;
        }
        void print() {
            if(top==-1)
                cout<<"stack is empty"<<endl;
            else
                cout<<"The element on the top of the stack is "<<A[top]<<endl;
        }
};
int main() {
    stack a,b;
    a.push(10);
    a.push(20);
    a.print();
    b.push(39);
    b.push(67);
    b.push(27);
    b.print();
    b.pop();
    b.print();
    a.pop();
    a.print();
    return 0;
}