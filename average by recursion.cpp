#include <bits/stdc++.h>
using namespace std;

long long sumo(int n, vector<int>&v, long long sum= 0) {
  if(n==v.size()){
    return sum;
  }
  return v[n]+sumo(n+1,v,sum);
}

int main() {
     int n;
     cin>>n;
     vector<int>v(n);
     for(int i=0;i<n;i++){
       cin>>v[i];
     }
    long long sum=sumo(0,v)/v.size();
    cout<<sum;
    return 0;
}
