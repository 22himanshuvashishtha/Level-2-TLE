#include <bits/stdc++.h>
using namespace std;

//#define mod (ll)(1e9+7)
//typedef long long ll;

void solve(){
  int n;
  cin>>n;
  vector<int>v(n);
  for(int i=0;i<n;i++){
    cin>>v[i];
  }
  vector<int>vec(n,0);
  
  for(int k=0;k<30;k++){
    bool flag=false;
    for(int i=0;i<n;i++){
      if((v[i]&(1<<k))&& flag == false){
        flag =true;
      }else if(flag==true && (v[i] & 1<<k)==0){
        vec[i]+=(1<<k);
      }
    }
  }
    for(int i=0;i<n;i++){
      cout<<vec[i]<<" ";
    }
    cout<<endl;
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
