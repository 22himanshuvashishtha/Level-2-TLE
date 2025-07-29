#include <bits/stdc++.h>
using namespace std;

void karo(int n,map<int,int>& m){
  int count=0;
  for(int i=2;i*i<=n;i++){
      while(n%i==0){
        m[i]++;
        n/=i;
      }
  }
  if(n>1){
    m[n]++;
  }
}
void solve() {
    int n;
    cin>>n;
    vector<int>v(n);
    map<int,int>m;
    for(int i=0;i<n;i++){
      cin>>v[i];
      karo(v[i],m);
    }
    for(auto it:m){
      if(it.second %n!=0){
        cout<<"NO"<<endl;
        return;
      }
    }
    cout<<"YES"<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
