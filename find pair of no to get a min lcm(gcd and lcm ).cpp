#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n;
    cin >> n;

    long long a = 1, b = n; 
    for (long long i = sqrt(n); i >= 1; --i) {
        if (n % i == 0) {
            long long j = n / i;
            if (__gcd(i, j) == 1) {
                a = i;
                b = j;
                break; 
            }
        }
    }
    cout << a << " " << b << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();

    return 0;
}
