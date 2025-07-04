#include <bits/stdc++.h>
using namespace std;

long long ans = LLONG_MIN; 
int g[8][8];
int c=0;

bool is_valid(int i,int j){
  if(g[i][j]=='*')
  return false;
  
  for(int k=i;k>=0;k--){
    if(g[k][j]=='Q'){
      return false;
    }
  }
  for(int k=i,p=j;k>=0,p>=0;k--,p--){
    if(g[k][j]=='Q'){
      return false;
    }
  }
  for(int k=i,p=j;k>=0,p<8;k--,p++){
    if(g[k][j]=='Q'){
      return false;
    }
  }
  
  return true;
}
void solve(int i=0) {
  if(i==8){
    c++;
    return;
  }  
  for(int j=0;j<8;j++){
    if(is_valid(i,j)){
      g[i][j]='Q';
      solve(i+1);
      g[i][j]='.';
    }
  }
}

int main() {
    for(int i=0;i<8;i++){
      for(int j=0;j<8;j++){
        cin>>g[i][j];
      }
    }
    solve();
    cout <<c<< "\n";
}
