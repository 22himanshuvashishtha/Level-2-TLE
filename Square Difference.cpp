#include <bits/stdc++.h>
using namespace std;


void solve() {
    long long a,b;
    cin>>a>>b;
    long long ans=0;
    if(a-b !=1){
      cout<<"NO"<<endl;
      return;
    }
    long long no=a+b;
    int count=0;
    for(long long i=2;i*i<=no;i++){
      if(no%i==0){
        while(no%i==0){
          count++;
          no/=i;          
        }
      }
    }
    if(no>1){
      count++;
    }
    if(count==1){
      cout<<"YES"<<endl;
    }else{
      cout<<"NO"<<endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) 
    solve();

    return 0;
}
