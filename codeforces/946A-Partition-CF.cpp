#include <bits/stdc++.h>
using namespace std;
int main()
{
	int sum=0,n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	for(int i=0;i<n;i++)
	sum=sum+abs(arr[i]);
	cout << sum;
	return 0;
}