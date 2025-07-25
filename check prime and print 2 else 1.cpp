#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n){
  if (n <= 1) {
        return false;
    }
    if (n <= 3) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    for (int i = 5; i * i <= n; i = i + 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}
void solve() {
    int n;
    cin>>n;
    if(n==1){
      cout<<"1"<<endl;
      cout<<"1";
      return;
    }
    if(n==2){
      cout<<1<<endl;
      cout<<"1 1";
      return;
    }
    vector<int>v;
    bool flag=false;
    for(int i=2;i<n+2;i++){
      if(isPrime(i)==true){
        v.push_back(2);
      }else{
        v.push_back(1);
        flag=true;
      }
    }
    if(n>2){
      cout<<"2";
    }else{
      cout<<"1";
    }
    cout<<endl;
    for(auto it:v){
      cout<<it<<" ";
    }
    
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
