#include <bits/stdc++.h>
using namespace std;

// void printv(vector<int> a) {
//     for(int i=0;i<a.size();i++)
//         cout<<a[i]<<" ";
//     cout<<endl;
// }

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,i;
        cin>>n;
        vector<int> a;
        bool flag=false;
        for(i=0;i<n;i++) {
            int x;
            cin>>x;
            if(!flag && x!=-1) {
                flag=true;
                a.push_back(x);
            }
            else if(flag)
                a.push_back(x);
        }
        // printv(a);
        if(a.size()==0) {
            cout<<"inf"<<endl;
            continue;
        }
        for(i=a.size()-1;i>=0;i--) {
            if(a[i]==-1)
                a.pop_back();
            else
                break;
        }
        // printv(a);
        for(i=a.size()-2;i>=0;i--)
            if(a[i]==-1 && abs(a[i+1])!=1)
                a[i]=a[i+1]-1;
        // printv(a);
        flag=true;
        for(int i=1;i<a.size();i++)
            if(a[i]-a[i-1]!=1)
                flag=false;
        if(flag) {
            cout<<"inf"<<endl;
            continue;
        }
        int count=0,mincount=a.size(),mini=-1,k=-1;
        for(i=a.size()-1;i>=0;i--) {
            if(a[i]==-1)
                ++count;
            else {
                if(count!=0 && count<mincount) {
                    mincount=count;
                    mini=i;
                    count=0;
                }
            }
        }
        // cout<<count<<" "<<mincount<<" "<<mini<<endl;
        if(mini!=-1) {
            for(i=mini+1;;i++) {
                // cout<<a[i]<<endl;
                if(a[i]==1) {
                    k=a[i-1];
                    break;
                }
                else
                    a[i]=a[i-1]+1;
                // cout<<a[i]<<endl;
            }
        }
        else {
            for(i=1;i<a.size();i++) {
                if(a[i]==1) {
                    k=a[i-1];
                    break;
                }
            }
        }
        // printv(a);
        int io=a[0]-1;
        // cout<<io<<" "<<k<<endl;
        for(i=0;i<a.size();i++) {
            if(a[i]==-1)
                continue;
            else if(a[i]==(((io+i)%k)+1))
                continue;
            else
                break;
        }
        if(i==a.size())
            cout<<k<<endl;
        else
            cout<<"impossible"<<endl;
    }
    return 0;
}