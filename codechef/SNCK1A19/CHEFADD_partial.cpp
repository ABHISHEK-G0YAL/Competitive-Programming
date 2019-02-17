#include <bits/stdc++.h>
using namespace std;
#define ui unsigned int

// int pos(int a,int b,bitset<8> c,int i=0,bool ci=0) {
//     int n=0,m=0;
//     if((i==8) && (a==0) && (b==0))
//         return 1;
//     if(ci) {
//         if(c[i]) {
//             if(a>0 && b>0)
//                 n=pos(a-1,b-1,c,i+1,1);
//             m=pos(a,b,c,i+1,0);
//         }
//         else {
//             if(a>0)
//                 n=pos(a-1,b,c,i+1,1);
//             if(b>0)
//                 m=pos(a,b-1,c,i+1,1);
//         }
//     }
//     else {
//         if(c[i]) {
//             if(a>0)
//                 n=pos(a-1,b,c,i+1,0);
//             if(b>0)
//                 m=pos(a,b-1,c,i+1,0);
//         }
//         else {
//             if(a>0 && b>0)
//                 n=pos(a-1,b-1,c,i+1,1);
//             m=pos(a,b,c,i+1,0);
//         }
//     }
//     return n+m;
// }
int main()
{
    // int count=1;
    // bitset<8> s;
    // cout<<s<<endl;
    // cout<<pos(2,2,s)<<endl;
    int t;
    cin>>t;
    while(t--) {
        ui A,B,C,count=0;
        cin>>A>>B>>C;
        bitset<32> ai(A),bi(B);
        for(int i=0;i<=C;i++) {
            int a=i,b=C-i;
            bitset<32> ao(a),bo(b);
            if(ai.count()==ao.count() && bi.count()==bo.count())
                ++count;
        }
        cout<<count<<endl;
    }
    // for(int i=0;i<=8;i++) {
    //     int a=i,b=797-i;
    //     int flag_A=0;
    //     int flag_B=0;
    //     bitset<4> A(a),B(b);
    //     for(int i=0;i<4;i++) {
    //         if(A[i]==1)
    //             ++flag_A;
    //         if(B[i]==1)
    //             ++flag_B;
    //     }
    //     if(flag_A==2 && flag_B==2) {
    //         cout<<count<<endl;
    //         cout<<i<<"\t"<<8-i<<endl;
    //         cout<<A<<"\n"<<B<<"\n"<<endl;
    //         ++count;
    //     }
    // }
    return 0;
}
