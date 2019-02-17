#include <iostream>
#define ui unsigned int
using namespace std;

bool isbetter(ui a[3],ui b[3]) {
    if((a[0]>=b[0] && a[1]>=b[1] && a[2]>=b[2]) && (a[0]>b[0] || a[1]>b[1] || a[2]>b[2]))
        return true;
    else if((a[0]<=b[0] && a[1]<=b[1] && a[2]<=b[2]) && (a[0]<b[0] || a[1]<b[1] || a[2]<b[2]))
        return true;
    else
        return false;
}

int main() {
    ui t;
    cin>>t;
    while(t--) {
        ui a[3][3];
        for(ui i=0;i<3;i++)
            for(ui j=0;j<3;j++)
                cin>>a[i][j];
    if(isbetter(a[0],a[1]) && isbetter(a[0],a[2]) && isbetter(a[1],a[2]))
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;
    }    
    return 0;
}