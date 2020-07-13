// 

#include <iostream>
#define pb pushBack
using namespace std;

class linkedList {
    public:
    int data; 
    linkedList *next=NULL; 
    linkedList *tail=this;
    linkedList *pushBack(int new_data) { 
        tail->data = new_data;
        tail->next = new linkedList;
        tail = tail->next;
        return tail;
    }
    linkedList *getNext() {
        if(next->next==NULL)
            return NULL;
        return next;
    }
};
int main()
{
    linkedList list;
    int n,x; cin>>n;
    while(n--) {
        cin>>x;
        cout<<list.pb(x)<<endl;
    }
    linkedList* curr=&list;
    while(curr != NULL){
        cout<<curr<<" "<<curr->data<<endl;
        curr=curr->getNext();
    }
    return 0;
}