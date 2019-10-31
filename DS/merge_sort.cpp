#include<bits/stdc++.h>
using namespace std;

void merge(int input[], int size) {
  int out[size],mid=(size+1)/2;
  int p1=0,p2=mid;
  for(int i=0;i<size;i++) {
    if(p1==mid)
      out[i]=input[p2++];
    else if(p2==size)
      out[i]=input[p1++];
    else if(input[p1]<=input[p2])
      out[i]=input[p1++];
    else
      out[i]=input[p2++];
  }
  for(int i=0;i<size;i++)
    input[i]=out[i];
}
void mergeSort(int input[],int size) {
  if(size<=1)
    return;
  else {
    int mid=(size+1)/2;
    mergeSort(input,mid);
    mergeSort(input+mid,size-mid);
    merge(input,size);
  }
}
int main() {
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    mergeSort(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}


// #include<bits/stdc++.h>
// using namespace std;

// void merge(int input[], int size) {
//   int out[size],mid=(size+1)/2,p1=0,p2=mid,i=0;
//   while(i<size) {
//     if(p1==mid) {
//       out[i]=input[p2];
//       ++p2;
//     }
//     else if(p2==size) {
//       out[i]=input[p1];
//       ++p1;
//     }
//     else if(input[p1]<=input[p2]) {
//       out[i]=input[p1];
//       ++p1;
//     }
//     else {
//       out[i]=input[p2];
//       ++p2;
//     }
//     ++i;
//   }
//   for(int x=0;x<size;x++)
//     input[x]=out[x];
// }
// void mergeSort(int input[], int size) {
//   if(size<=1)
//     return;
//   else {
//     int mid=(size+1)/2;
//     mergeSort(input,mid);
//     mergeSort(input+mid,size-mid);
//     merge(input,size);
//   }
// }
// int main() {
//     int n; cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++)
//         cin>>arr[i];
//     mergeSort(arr,n);
//     for(int i=0;i<n;i++)
//         cout<<arr[i]<<" ";
//     cout<<endl;
// }