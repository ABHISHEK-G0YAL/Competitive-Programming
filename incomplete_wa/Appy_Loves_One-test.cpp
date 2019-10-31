#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n=15;
    int q=2*n+1;
    int k=n;
    cout<<n<<' '<<q<<' '<<k<<endl;
    bool boo[n]={1,0,1,1,1,1,0,1,1,1,1,1,0,1,1};
    for(int i=0;i<n;i++)
        cout<<boo[i]<<" ";
    cout<<endl;
    vector<char> str(q);
    for(int i=0;i<q;i++){
        if(i%2)
            str[i]='!';
        else
            str[i]='?';
    }
    for(int i=0;i<q;i++)
        cout<<str[i];
    cout<<endl;
    return 0;
}