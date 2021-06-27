// https://www.codechef.com/UCSL2020/problems/ENDLE001

#include <bits/stdc++.h>
using namespace std;

void print_deque(deque<int> &dq) {
    if(dq.empty())
        return;
    for(int i : dq)
        cout << i << ' ';
    cout << endl;
}

int main() {
    int n, x;
    cin >> n;
    deque<int> stack, queue;
    for(int i = 0; i < n; i++) {
        cin >> x;
        if(queue.empty() and stack.empty())
            queue.push_back(x);
        else if(x >= queue.back())
            queue.push_back(x);
        else if(stack.empty() or x <= stack.front())
            stack.push_front(x);
        else {
            while(!stack.empty()) {
                if(stack.front() < queue.front()) {
                    queue.push_back(stack.front());
                    stack.pop_front();
                }
                else {
                    bool flag1 = true;
                    for(int i : queue)
                        if(stack.front() <= i)
                            flag1 = false;
                    if(flag1 and is_sorted(queue.begin(), queue.end())) {
                        queue.push_back(stack.front());
                        stack.pop_front();
                    }
                    else if(stack.front() == queue.back()) {
                        queue.push_back(stack.front());
                        stack.pop_front();
                    }
                    else {
                        queue.push_back(queue.front());
                        queue.pop_front();
                    }
                }
            }
            while(queue.front() < x) {
                queue.push_back(queue.front());
                queue.pop_front();
            }
            stack.push_front(queue.front());
            queue.pop_front();
            stack.push_front(x);
            while(queue.front() > queue.back()) {
                queue.push_back(queue.front());
                queue.pop_front();
            }
        }
        print_deque(queue);
        print_deque(stack);
    }
}