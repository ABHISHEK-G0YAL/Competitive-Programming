// https://www.codechef.com/SATA2019/problems/SAT103

#include <bits/stdc++.h>
using namespace std;

void DFS(int i, auto &adjList, auto &visited) {
    visited[i] = true;
    for(auto &j : adjList[i])
        if(!visited[j])
            DFS(j, adjList, visited);
} 

int main() {
    int t, n, e, x, y;
    cin >> t;
    while(t--) {
        cin >> n >> e;
        vector<vector<int> > adjList(n + 1);
        for(int i = 0; i < e; i++) {
            cin >> x >> y;
            adjList[x].push_back(y);
            adjList[y].push_back(x);
        }
        vector<bool> visited(n + 1, false);
        int cost = -1;
        for(int i = 1; i < visited.size(); i++) {
            if(!visited[i]) {
                DFS(i, adjList, visited);
                cost += i;
            }
        }
        cout << cost << endl;
    }
}