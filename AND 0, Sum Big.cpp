#include <bits/stdc++.h>
using namespace std;
#define mod (ll)(1e9+7)
typedef long long ll;
 
ll solve(ll n,ll m){
  if(m==0)return 1;
  ll ans=solve(n,m-1);
  ans%=mod;
  ans*=n;
  ans%=mod;
  return ans;
  
}
int main() 
{
    int l;
    cin>>l;
    while(l--){
    ll n,m;
    cin>>n>>m;
    cout<<solve(n,m)<<endl;
    }
    return 0;
}
