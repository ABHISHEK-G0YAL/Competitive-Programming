#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,m,x,k,nwe,nwo,e,o,me,mo;
	string s;
	cin>>t;
	while(t--)
	{	
		cin>>n>>m>>x>>k;
		cin>>s;
		nwe=0;nwo=0;
		for(int i=0;i<k;i++)
		{
			if(s[i]=='E')
				++nwe;
			else
				++nwo;
		}
		me=m/2;mo=m-me;
        e=min(nwe,x)*me;
        o=min(nwo,x)*mo;
		int mno=min(nwe,e)+min(nwo,o);
		if(mno>=n)
		cout<<"yes"<<endl;
		else
		cout<<"no"<<endl;
	}
	return 0;
}
// Older Version (100 pts)

// #include<iostream>
// using namespace std;
// int main()
// {
//     int t,i,j,e,o,count;
//     long int n,m,x,k;
//     cin>>t;
//     for(i=0;i<t;i++)
//     {
//         int p=0;count=1;
//         cin>>n>>m>>x>>k;
//         string s;
//         cin>>s;
//         e=0;o=0;
//         for(j=0;j<k;j++)
//         {
//             if(s[j]=='E')
//             e++;
//             else 
//             o++;
//         }
//         while( count <= m && ( (o>0)  ||  (e>0) ) )
//         {
//             if(o<x)
//             {
//                 p=p+o;
//                 o=0;
//             }
//             else
//             {
//                 p=p+x;
//                 o=o-x;
//             }
//             ++count;
//             if(count>m)
//             break;
//             if(e<x)
//             {
//                 p=p+e;
//                 e=0;
//             }
//             else
//             {
//                 p=p+x;
//                 e=e-x;
//             }
//             ++count;
//         }
//         if(p>=n)
//             cout<<"yes"<<endl;
//         else
//             cout<<"no"<<endl;
//     } 
//     return 0;
// }