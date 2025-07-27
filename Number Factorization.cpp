#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n;
    cin >> n;
    map<long long, long long> m;
    long long x = 0;

    // Correct factorization
    for (int i = 2; 1LL * i * i <= n; i++) {
        if (n % i == 0) {
            long long count = 0;
            while (n % i == 0) {
                count++;
                n /= i;
            }
            x = max(x, count);
            m[i] = count;
        }
    }
    if (n != 1) {
        m[n] = 1;
        x = max(x, 1LL);
    }

    int ans = 0;
    for (int j = 1; j <= x; j++) {
        long long p = 1;
        for (auto& it : m) {
            if (it.second > 0) {
                it.second--;
                p *= it.first;
            }
        }
        ans += p;
    }

    cout << ans << endl;
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
