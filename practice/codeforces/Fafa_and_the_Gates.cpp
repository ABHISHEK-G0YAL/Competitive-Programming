// http://codeforces.com/contest/935/problem/B

#include <iostream>
using namespace std;
bool chkflag(int flag,int xflag)
{
	if(flag!=xflag && xflag!=0)
	return true;
	else
	return false;
}
int main()
{
	int n,i,x=0,y=0,flag=0,count=0,xflag=0;
	string s;
	cin >> n;
	cin >> s;
	for(i=0;i<n;i++)
	{
		if(s[i]=='U')
			y+=1;
		else
			x+=1;
		if(x>y)
			flag=1;
		else if(y>x)
			flag=-1;
		if(chkflag(flag,xflag))
			count+=1;
		xflag=flag;
	}
	cout << count;
}