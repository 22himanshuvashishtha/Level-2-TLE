#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long n) {
    if (n < 2) return false;
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    vector<long long> v(t);
    for (int i = 0; i < t; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < t; i++) {
        long long root = round(sqrt(v[i]));
        if (root * root == v[i] && isPrime(root)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
