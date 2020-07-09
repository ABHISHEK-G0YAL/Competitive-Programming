// https://www.hackerrank.com/challenges/deque-stl/problem
// Accepted

#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int a[], int n, int k){
    deque<int> q;
    int max = 0;
    for(int i = 0; i < n; i++) {
        while(!q.empty() and q.front() <= i - k)
            q.pop_front();
        while(!q.empty() and a[q.back()] < a[i])
            q.pop_back();
        q.push_back(i);
        if(i >= k - 1)
            cout << a[q.front()] << " ";
    } cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t, n, k, i, a[100005];
	cin >> t;
	while(t--) {
    	cin >> n >> k;
    	for(i = 0; i < n; i++)
      		cin >> a[i];
    	printKMax(a, n, k);
  	}
  	return 0;
}

