// https://www.facebook.com/hackercup/problem/862237970786911/
// Incorrect Submission

#include <bits\stdc++.h>
#define ll long long
using namespace std;
class node {
public:
    int wt,a,b;
};
bool comprator(node A,node B) {
    return A.wt<B.wt;
}
void printAllEdges(vector<vector<int>> graph) {
    for(int i=0;i<graph.size();i++) {
        for(int j=0;j<graph[i].size();j++) {
            if(graph[i][j] != 0) {
                cout<<i<<" "<<j<<" "<<graph[i][j]<<endl;
            }
        }
    }
}
int minDistance(int dist[], bool sptSet[],int V) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}
int dijkstra(vector<vector<int>> graph, int src, int dest) {
    int V=graph.size();
    int dist[V];
    bool sptSet[V];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
    dist[src] = 0;
    for (int count = 0; count < V-1; count++) {
        int u = minDistance(dist, sptSet, V);
        sptSet[u] = true;
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u]+graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    } return dist[dest];
}
int main() {
    ll t, n, m;
    cin >> t;
    for(ll x = 1; x <= t; x++) {
        cin >> n >> m;
        vector<node> req(m);
        for(int i = 0;i < m; i++) {
            cin >> req[i].a >> req[i].b >> req[i].wt;
        } sort(req.begin(),req.end(),comprator);
        vector<vector<int>> adjM(n+1,vector<int>(n+1,0));
        int edgeCount=0;
        for(int i = 0;i < m; i++) {
            if(req[i].wt < dijkstra(adjM,req[i].a,req[i].b) && adjM[req[i].a][req[i].b]==0)
                adjM[req[i].a][req[i].b] = req[i].wt, adjM[req[i].b][req[i].a] = req[i].wt, edgeCount+=1;
            else if(req[i].wt == dijkstra(adjM,req[i].a,req[i].b)) continue;
            else goto impossible;
        } cout<<"Case #"<<x<<": "<<edgeCount<<endl;
        printAllEdges(adjM);
        continue;
        impossible:cout<<"Case #"<<x<<": Impossible"<<endl;
	}
}