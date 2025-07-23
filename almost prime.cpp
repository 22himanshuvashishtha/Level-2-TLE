#include <bits/stdc++.h>
using namespace std;

#define int long long
const int n=1e7;


void solve() {
    int n;
    cin>>n;
    int ans=0;
    for(int i=2;i<=n;i++){
      int count=0;
      int num=i;
      for(int j=2;j*j<=num;j++){
        if(num%j==0){
          count++;
          while(num%j==0){
            num/=j;
          }
        }
      }
      if(num>1){
        count++;
      }
      if(count==2){
        ans++;
      }
    }
    
      cout<<ans<<endl;
  
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //int t;
    //cin >> t;
    //while (t--) 
    solve();

    return 0;
}
