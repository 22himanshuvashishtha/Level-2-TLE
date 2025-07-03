#include <bits/stdc++.h>
using namespace std;

long long ans = LLONG_MIN; 
int n,m;


void solve(int inx1, int inx2, long long sum, vector<vector<int>> &a) {
    sum += a[inx1][inx2];
    
    if(inx1 == n - 1 && inx2 == m - 1){
      ans=max(ans,sum);
      return;
    }
    if (inx1 + 1 < n) {
        solve(inx1 + 1, inx2, sum, a);
    }

    if (inx2 + 1 < m) {
        solve(inx1, inx2 + 1, sum, a);
    }
}

int main() {
   cin >> n>>m;
    vector<vector<int>>a(n,vector<int>(m));
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        cin>>a[i][j];
      }
    }
    solve(0,0,0LL,a);
    cout << ans << "\n";
}
