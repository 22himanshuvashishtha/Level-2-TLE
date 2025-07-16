#include <bits/stdc++.h>
using namespace std;

//#define mod (ll)(1e9+7)
//typedef long long ll;

void solve(){
  int n;
  cin>>n;
  vector<int>v(n);
  vector<int>vec(1024,0);
  for(int i=0;i<n;i++){
    cin>>v[i];
    vec[v[i]]++;
  }
  int ans=-1;
  
  for(int k=1;k<=1023;k++){
    vector<int>fre(1024,0);
    for(int i=0;i<n;i++){
      fre[v[i]^k]++;
    }
    bool flag=true;
    for(int i=0;i<1023;i++){
      if(vec[i]!=fre[i]){
        flag=false;
        break;
      }
    }
    if(flag==true){
      ans=k;
      break;
    }
  }
  cout<<ans<<endl;
  
}
int main() 
{
    int p;
    cin>>p;
    while(p--){
    solve();
    }
    return 0;
}
