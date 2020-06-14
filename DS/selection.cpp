#include<iostream>
using namespace std;
int main()
{
    int n,min_idx,temp;
    cout<<"enter the value of n"<<endl;
    cin>>n;
    int a[n],i,j;
    cout<<"elements in array are "<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for( i=0;i<n;i++)
    {
        min_idx=i;
        for( j=i+1;j<n;j++)
        {
            if(a[j]<a[min_idx])
            {
                min_idx=j;
            }
        }
        temp=a[i];
        a[i]=a[min_idx];
        a[min_idx]=temp;
    }
    cout<<"sorted array is "<<endl;
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
