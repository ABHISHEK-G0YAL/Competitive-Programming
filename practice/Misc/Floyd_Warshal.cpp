#include<iostream>
#include<vector>
#define INF 100000000
using namespace std;

void floydWarshal(vector<vector<int> > &cost){
    int n = cost.size();
    for(int k = 0; k<n; k++){
        for(int i = 0; i<n; i++)
            for(int j = 0; j<n; j++)
                if(cost[i][k] + cost[k][j] < cost[i][j])
                    cost[i][j] = cost[i][k] + cost[k][j];
    }
}

int main() {
    int n, m, q, u, v, w;
    cin >> n >> m >> q;
    vector<vector<int> > adm(n+1, vector<int>(n+1, INF));
    for(int i = 0; i <= n; i++)
        adm[i][i] = 0;
    while(m--) {
        cin >> u >> v >> w;
        adm[u][v] = w;
    }
    floydWarshal(adm);
    while (q--) {
        cin >> u >> v;
        cout << (adm[u][v] != INF ? adm[u][v] : -1) << endl;
    }
}