#include <bits/stdc++.h>
#define ull unsigned long long

using namespace std;

ull digisum (ull n) {
  ull sum=0;
  while(n>0) {
    sum+=(n%10);
    n=n/10;
  }
  return sum;
}

ull alldigisum (ull n) {
  while(n>9){
    ull sum=0;
    while(n>0) {
      sum+=(n%10);
      n=n/10;
    }
    n=sum;
  }
  return n;
}

ull countstep (ull n) {
  ull count=0;
  while(n>9){
    ++count;
    ull sum=0;
    while(n>0) {
      sum+=(n%10);
      n=n/10;
    }
    n=sum;
  }
  return count;
}

int main() {
  ull t;
  cin>>t;
  while (t--) {
    ull n,d,count=0;
    cin>>n>>d;
    ull dig=alldigisum(n);
    ull firstdig=dig,mindig=dig;
    for(ull i=1;;i++) {
      dig=alldigisum(n+(i*d));
      if(firstdig == dig)
        break;
      if(dig < mindig) {
        mindig = dig;
        count = i;
      }
    }
    count+=countstep(n+(count*d));
    cout<<mindig<<" "<<count<<endl;
  }
  return 0;
}
