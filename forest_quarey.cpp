//https://cses.fi/problemset/result/13618916/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n+1, vector<char>(n+1, 0));
    vector<vector<long long>> prefix(n+1, vector<long long>(n+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> v[i][j];
            int x=0;
            if(v[i][j]=='*'){
             x=1;
             prefix[i][j] = x + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
            }else{
              x=0;
              prefix[i][j] = x + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
            }
            
        }
    }

    // Answer queries
    while (m--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        if (l1 > l2 || r1 > r2 || l1 < 1 || r1 < 1 || l2 > n || r2 > n) {
            cout << "0\n";
        } else {
            cout << (prefix[l2][r2] - prefix[l1-1][r2] - prefix[l2][r1-1] + prefix[l1-1][r1-1]) << '\n';
        }
    }

    return 0;
}
