// https://www.codechef.com/UCDS2020/problems/MIDLE003/

#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node *next = NULL;
    node(int d = -1) : data(d) {}
};

class MLL {
    bool circular = false;
    map<int, int> freq;
    unordered_map<int, node*> mp;
    node *const head = new node;
public:
    void insert_at_end(int x) {
        mp[x] = new node(x);
        node *temp = head;
        while(temp->next)
            temp = temp->next;
        temp->next = mp[x];
        ++freq[x];
    }
    void insert_after_node(node *temp, int d) {
        mp[d] = new node(d);
        node* next = temp->next;
        temp->next = mp[d];
        temp->next->next = next;
        ++freq[d];
    }
    void insert_before_or_after(int x, int y) {
        node *temp = head->next;
        while(temp) {
            if(temp->data == y) {
                insert_after_node(temp, x);
                return;
            }
            temp = temp->next;
        }
        temp = head;
        while(temp->next) {
            if(temp->next->data == x) {
                insert_after_node(temp, y);
                return;
            }
            temp = temp->next;
        }
    }
    void insert_in_middle_of(int x, int z, int y) {
        node *slow = head->next;
        while(slow) {
            if(slow->data == z)
                break;
            slow = slow->next;
        }
        node *fast = slow->next;
        while(fast) {
            if(fast->data == y)
                break;
            slow = slow->next;
            fast = fast->next;
            if(fast) fast = fast->next;
        }
        insert_after_node(slow, x);
    }
    void link_x_to_x_plus_p(int x, int p) {
        int i = 0;
        node* xp = mp[x];
        while(i < p) {
            if(xp->next) {
                xp = xp->next;
                ++i;
            }
            else {
                xp->next = head->next;
                ++freq[head->next->data];
                xp = xp->next;
                circular = true;
                ++i;
            }
        }
        --freq[mp[x]->next->data];
        mp[x]->next = xp;
        ++freq[xp->data];
    }
    // void debug() {
    //     node *temp = head->next;
    //     while(temp) {
    //         cout << temp->data << " ";
    //         temp = temp->next;
    //     }
    //     cout << endl;
    // }
    void print() {
        --freq[head->next->data];
        cout << circular << endl;
        int count = 0;
        for(auto &x : freq)
            if(x.second > 1)
                ++count;
        cout << count << endl;
        if(count == 0) {
            node *temp = head->next;
            while(temp) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        else {
            for(auto &x : freq)
                if(x.second > 1)
                    cout << x.first << " ";
            cout << endl;
            for(auto &x : freq)
                if(x.second > 1)
                    cout << x.second << " ";
            cout << endl;
            // debug();
        }
    }
};

int main() {
    MLL l;
    int q, i, x, y, z, p;
    char c;
    cin >> q;
    while(q--) {
        cin >> c;
        if(c == 'I') {
            cin >> i;
            if(i == 0) {
                cin >> x;
                l.insert_at_end(x);
            }
            if(i == 1) {
                cin >> y >> x;
                l.insert_before_or_after(x, y);
            }
            if(i == 2) {
                cin >> z >> y >> x;
                l.insert_in_middle_of(x, z, y);
            }
        }
        else {
            cin >> x >> p;
            l.link_x_to_x_plus_p(x, p);
        }
        // l.print();
        // cout << endl;
    }
    l.print();
}