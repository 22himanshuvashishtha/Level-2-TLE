#include <bits/stdc++.h>
using namespace std;

long long ans = LLONG_MAX; 

void solve(int idx, long long sum1, long long sum2, vector<int>& a) {
    if (idx == a.size()) {
        ans = min(ans, abs(sum1 - sum2));
        return;
    }

    solve(idx + 1, sum1 + a[idx], sum2, a);
    solve(idx + 1, sum1, sum2 + a[idx], a);
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    solve(0, 0, 0, a);
    cout << ans << "\n";
}
