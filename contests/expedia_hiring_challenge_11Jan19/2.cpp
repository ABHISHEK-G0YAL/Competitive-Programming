#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;

unordered_map<int, int> vis;
void bfs(unordered_map<int,vector<int>> g) {
    vis.clear();
    vis[1] = 0;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int top = q.front();
        q.pop();
        for(auto node : g[top]) {
            if(vis.find(node) == vis.end()) {
                vis[node] = vis[top]+1;
                q.push(node);
            }
        }
    }
}


int main(){
unordered_map<int,vector<int>> g;
vector<vector<int> > v;
v = {{6, 4, 3}, {6, 1, 7}, {1, 6, 7}, {7, 1, 2}, {7, 1, 3}, {3, 4, 7}, {6, 2, 3}};
for(int i=0; i < v.size(); i++) {
    for(int j=0; j < v[i].size(); j++) {
        g[i+1].push_back(v[i][j]);
    }
}
bfs(g);
cout << (vis[v.size()] ? vis[v.size()] : -1) << endl;
}