#include <iostream>
using namespace std;

int main() {
    int t,n;
    cin>>t;
    while(t--) {
        cin>>n;
        int x,a[n]={0},i1,i2;
        for(int i=0;i<n;i++) {
            cin>>x; ++a[x];
        } x=0; bool fl=true; 
        for(int i=0;i<n;i++) {
            if(a[i]>0) {
                ++x;
                if(fl) {
                    i1=i;
                    fl=0;
                }
                else
                    i2=i;
            }
        }
        if(x==1 && a[n-1]==n)
            cout<<0<<endl;
        else if(x==2 && i2-i1==1)
            cout<<a[i2]<<endl;
        else
            cout<<-1<<endl;
    }
}
 
#include <iostream>
using namespace std;

int main() {
    int t,n;
    cin>>t;
    while(t--) {
        cin>>n;
        int x,max=INT_MIN,min=INT_MAX,maxC,minC;
        for(int i=0;i<n;i++) {
            cin>>x;
            if(max<x) {
                max=x;
                maxC=0;
            }
            if(min>x) {
                min=x;
                minC=0;
            }
            if(x==max)
                ++maxC;
            if(x==min)
                ++minC;
        }
        if(max==min && max==n-1)
            cout<<0<<endl;
        else if(max==min && min==0)
            cout<<n<<endl;
        else if(max-min==1)
        }
            cout<<-1<<endl;
        else {
            
        }
    }
}
