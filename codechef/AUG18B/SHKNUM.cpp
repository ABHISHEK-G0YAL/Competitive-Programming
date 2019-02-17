#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

void modified_binary_search(vector<ull> &fx,ull &n,ull l,ull r,ull &low,ull &up)
{
    if((r-l)==1)
    {
        low=fx[l];
        up=fx[r];
    }
    else
    {
        ull mid=(r+l)/2;
        if(n>=fx[mid])
            modified_binary_search(fx,n,mid,r,low,up);
        else
            modified_binary_search(fx,n,l,mid,low,up);
    }
}
int main()
{
    const ull one=1;
    vector<ull> fx;
    for(ull x=0;x<=30;x++){
        for(ull y=0;y<=30;y++){
            if(x!=y)
            fx.push_back((one<<x)+(one<<y));}}
    sort(fx.begin(),fx.end());
    ull t;
    cin>>t;
    while(t--)
    {
        ull n;
        cin>>n;
        ull low,up;
        modified_binary_search(fx,n,0,fx.size()-1,low,up);
        cout<<min(up-n,n-low)<<endl;
    }
    return 0;
}

// #include <bits/stdc++.h>
// #define ull unsigned long long
// using namespace std;

// int main()
// {
//     const ull one=1;
//     vector<ull> fx;
//     for(ull x=0;x<=30;x++)
//         for(ull y=x+1;y<=30;y++)
//             fx.push_back((one<<x)+(one<<y));
//     sort(fx.begin(),fx.end());
//     ull t;
//     cin>>t;
//     while(t--)
//     {
//         ull n;
//         cin>>n;
//         vector<ull>::iterator low=lower_bound(fx.begin(),fx.end(),n);
//         vector<ull>::iterator up=upper_bound(fx.begin(),fx.end(),n);
//         cout<<min(*up-n,n-*low)<<endl;
//     }
//     return 0;
// }

// #include <bits/stdc++.h>
// #define ull unsigned long long
// using namespace std;

// void modified_binary_search(vector<ull> &fx,ull n,ull l,ull r,ull &low,ull &up)
// {
//     if((r-l)==1)
//     {
//         low=fx[l];
//         up=fx[r];
//     }
//     else
//     {
//         ull mid=(r+l)/2;
//         if(n>=fx[mid])
//             modified_binary_search(fx,n,mid,r,low,up);
//         else
//             modified_binary_search(fx,n,l,mid,low,up);
//     }
// }
// int main()
// {
//     const ull one=1;
//     vector<ull> fx;
//     for(ull x=0;x<=30;x++)
//         for(ull y=x+1;y<=30;y++)
//             fx.push_back((one<<x)+(one<<y));
//     sort(fx.begin(),fx.end());
//     ull t;
//     cin>>t;
//     while(t--)
//     {
//         ull n;
//         cin>>n;
//         ull low,up;
//         modified_binary_search(fx,n,0,fx.size()-1,low,up);
//         cout<<min(up-n,n-low)<<endl;
//     }
//     return 0;
// }

// #include <bits/stdc++.h>
// #define ui unsigned int
// using namespace std;

// int main()
// {
//     const ui one=1;
//     vector<ui> graph;
//     for(int x=0;x<=30;x++)
//         for(int y=x+1;y<=30;y++)
//             graph.push_back((one<<x)+(one<<y));
//     sort(graph.begin(),graph.end());
//     ui t;
//     cin>>t;
//     while(t--)
//     {
//         int n;
//         cin>>n;
//         int low=n+1,up=n-1;
//         while(!binary_search(graph.begin(),graph.end(),--low)){}
//         while(!binary_search(graph.begin(),graph.end(),++up)){}
//         cout<<min(up-n,n-low)<<endl;
//     }
//     return 0;
// }

// #include <iostream>
// #include <unordered_map>
// #define ui unsigned int
// using namespace std;

// int main()
// {
//     const ui one=1;
//     unordered_map <ui,pair<ui,ui> > graph;
//     for(int x=0;x<=30;x++)
//         for(int y=x+1;y<=30;y++)
//             graph[(one<<x) + (one<<y)]=make_pair(x,y);
//     ui t;
//     cin>>t;
//     while(t--)
//     {
//         int n,low,up;
//         cin>>n;
//         for(int i=n;;i--)
//         {
//             auto it=graph.find(i);
//             if(it!=graph.end())
//                 low=i;
//             else
//                 continue;
//             break;
//         }
//         for(int i=n;;i++)
//         {
//             auto it=graph.find(i);
//             if(it!=graph.end())
//                 up=i;
//             else
//                 continue;
//             break;
//         }
//         cout<<min(up-n,n-low)<<endl;
//     }
//     return 0;
// }

// #include <iostream>
// #include <unordered_map>
// #define ui unsigned int
// using namespace std;

// int main()
// {
//     const ui one=1;
//     unordered_map <ui,pair<ui,ui> > graph;
//     for(int x=0;x<=30;x++)
//         for(int y=x+1;y<=30;y++)
//             graph[(one<<x) + (one<<y)]=make_pair(x,y);
//     ui t;
//     cin>>t;
//     while(t--)
//     {
//         int n,low,up;
//         cin>>n;
//         for(int i=n;;i--)
//         {
//             try
//             {
//                 graph.at(i);
//                 low=i;
//                 break;
//             }
//             catch(...) {}
//         }
//         for(int i=n;;i++)
//         {
//             try
//             {
//                 graph.at(i);
//                 up=i;
//                 break;
//             }
//             catch(...) {}
//         }
//         cout<<min(up-n,n-low)<<endl;
//     }
//     return 0;
// }