#include <iostream>
using namespace std;
int main()
{
	int i,n;
	cin >> n;
	int arr[n+1];
	for(i=1;i<n+1;i++)
	cin >> arr[i];
	for(i=1;i<n+1;i++)
	{
		if(arr[arr[arr[i]]]==i)
		{
			cout << "YES";
			break;
		}
	}
	if(i>=n-1)
	cout << "NO";
	return 0;
}
