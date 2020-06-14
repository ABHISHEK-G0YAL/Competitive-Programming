#include <iostream>
#include <string>
#include <vector>
using namespace std;

int cti(char x) {
    return x-'A';
}
char itc(int i) {
    return i+'A';
}

int main() {
    int t,f;
    char x;
    cin>>t>>f;
    while (t--) {
        int n=120;
        string output="";
        vector<vector<int> > hash(5);
        bool used[5]={};
        vector<int> missing_sets;
        for(int i=1;i<=595;i+=5) {
            cout<<i<<endl;
            cin>>x;
            hash[cti(x)].push_back(i);
        }
        for(int y=0;y<5;y++) {
            n=n/(5-y);
            for(int i=0;i<5;i++) {
                if(hash[i].size()==n-1 && !used[i]) {
                    output+=itc(i);
                    missing_sets=hash[i];
                    used[i]=true;
                }
                else if(hash[i].size()==n) {
                    hash[i].clear();
                }
            }
            for(int i=0;i<missing_sets.size();i++) {
                cout<<missing_sets[i]+1+y<<endl;
                cin>>x;
                hash[cti(x)].push_back(missing_sets[i]);
            }
        }
        cout<<output<<endl;
        cin>>x;
    }
}