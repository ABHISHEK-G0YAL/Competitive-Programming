#include<iostream>
using namespace std;

struct node
{
    int data;
    node* link;
};
node* top=NULL;
void push(int x)
{
    node* temp=new node;
    temp->data=x;
    temp->link=top;
    top=temp;
}
void pop()
{
    node* temp;
    if(top==NULL)
        cout<<"empty stack"<<endl;
    else
        top=temp;
    top=top->link;
    free(temp);

}
void print()
{


    if(top==NULL)
        cout<<"empty"<<endl;
    else
        cout<<top->data<<endl;
}
int main()
{
    push(3);
    push(4);
    print();
    pop();
    print();
}
