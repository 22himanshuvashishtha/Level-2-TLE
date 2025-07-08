#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<vector<long long>> v(n, vector<long long>(n));
    vector<vector<long long>> prefix(n+1, vector<long long>(n+1, 0));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
            prefix[i+1][j+1] = v[i][j] + prefix[i][j+1] + prefix[i+1][j] - prefix[i][j];
        }
    }
    while (m--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        long long sum = prefix[l2][r2] - prefix[l1-1][r2] - prefix[l2][r1-1] + prefix[l1-1][r1-1];
        cout << sum << '\n';
    }
    
    return 0;
}
