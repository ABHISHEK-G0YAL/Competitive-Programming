// https://www.codechef.com/problems/HMAPPY1

#include <iostream>
#include <string>
using namespace std;

int main() {
    int n,q,k,m_count=0,l_count=0,r_count=0,s_count=0,r;
    cin>>n>>q>>k;
    bool boo[n],l=1;
    string str;
    for(int i=0;i<n;i++)
        cin>>boo[i];
    cin>>str;
    for(int i=0;i<n;i++) {
        if(boo[i]) {
            if(l)
                ++l_count;
            ++r_count;
        }
        else {
            if(r_count>m_count) {
                m_count=r_count;
                r=n-i;
            }
            l=0;
            r_count=0;
        }
    }
    if(r_count>m_count) {
        m_count=r_count;
        r=0;
    }
    // cout<<l_count<<" "<<r_count<<" "<<m_count<<" "<<r<<endl;
    // for(int i=0;i<q;i++) {
    //     s_count%=n;
    //     if(str[i]=='!')
    //         ++s_count;
    //     else {
    //         if(s_count<=r) {
    //             if(s_count<=r_count)
    //                 cout<<min(k,max(m_count,l_count+s_count))<<endl;
    //             else
    //                 cout<<min(k,max(m_count,l_count+r_count))<<endl;
    //         }
    //         else {
    //             if(s_count<=r_count)
    //                 cout<<min(k,max(m_count-s_count,l_count+s_count))<<endl;
    //             else
    //                 cout<<min(k,max(m_count-(s_count-r),l_count+r_count))<<endl;
    //         }
    //     }
    //     // cout<<s_count<<endl;
    // }
    for(int i=0;i<q;i++) {
        if(str[i]=='!') {
            ++s_count;
        }
        else {
            if(s_count<=r) {
                if(s_count<=r_count)
                    cout<<min(k,max(m_count,l_count+s_count))<<endl;
                else
                    cout<<min(k,max(m_count,l_count+r_count))<<endl;
            }
            else {
                if(s_count<=r_count)
                    cout<<min(k,max(m_count-s_count,l_count+s_count))<<endl;
                else
                    cout<<min(k,max(m_count-(s_count-r),l_count+r_count))<<endl;
            }
        }
    }
}