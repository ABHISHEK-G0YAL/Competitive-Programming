// https://www.codechef.com/UCSD2020/problems/DSLA5

#include <bits/stdc++.h>
using namespace std;
class process {
public:
    int id, aT, bT;
};
bool byArrivalTime(process &p1, process &p2) {
    return p1.aT < p2.aT;
}
int main() {
    int n, tq = 1, t = 0;
    cin >> n;
    deque<process> simpleList(n);
    for(auto &p : simpleList)
        cin >> p.id >> p.aT >> p.bT;
    sort(simpleList.begin(), simpleList.end(), byArrivalTime);
    deque<process> circularList;
    deque<process> &cl = circularList;
    auto i = 0;
    while(!simpleList.empty() or !cl.empty()) {
        if(i == cl.size())
            i = 0;
        if(!circularList.empty()) {
            cout << cl[i].id << " ";
            cl[i].bT -= tq;
            if(cl[i].bT == 0) {
                cl.erase(cl.begin() + i);
                --i;
            }
            ++i;
        }
        while(!simpleList.empty() and simpleList.front().aT <= t) {
            circularList.push_back(simpleList.front());
            simpleList.pop_front();
        }
        t += tq;
    }
}
// class Node { 
//   process p;
//   Node *next;
//   Node(process p)
// }; 
// struct Node* head = NULL; 
// void insert(int newdata) { 
//   struct Node *newnode = (struct Node *)malloc(sizeof(struct Node)); 
//   struct Node *ptr = head;  
//   newnode->data = newdata; 
//   newnode->next = head; 
//   if (head!= NULL) { 
//       while (ptr->next != head) 
//          ptr = ptr->next; 
//       ptr->next = newnode; 
//   } else
//       newnode->next = newnode;   
//       head = newnode; 
// }