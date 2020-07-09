// https://www.hackerrank.com/challenges/bon-appetit/problem
// Accepted

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,k,sum=0,b;
    cin>>n>>k;
    int pr[n];
    for(int i=0;i<n;i++)
        cin>>pr[i];
    cin>>b;
    for(int i=0;i<n;i++)
        sum+=pr[i];
    if((sum-pr[k])/2!=b)
        cout<<b-((sum-pr[k])/2);
    else
        cout<<"Bon Appetit";
    return 0;
}
