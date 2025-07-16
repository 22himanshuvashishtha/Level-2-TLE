#include <bits/stdc++.h>
using namespace std;

//#define mod (ll)(1e9+7)
//typedef long long ll;

void solve(){
  string x,y;
  cin>>x>>y;
  int p1,p2;
  reverse(x.begin(),x.end());
  reverse(y.begin(),y.end());
  for(int i=0;i<y.length();i++){
    if(y[i]=='1'){
      p1=i;
      break;
    }
  }
  for(int i=p1;i<x.length();i++){
    if(x[i]=='1'){
      p2=i;
      break;
    }
  }
  cout<<p2-p1<<endl;
  
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
