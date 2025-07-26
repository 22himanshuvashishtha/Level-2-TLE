#include <iostream>
#include <vector>
#include <numeric> 
 
using namespace std;
 
void solve() {
    int n, k;
    cin >> n >> k;
 
    vector<int> factors;
    int temp_n = n;
    for (int i = 2; i * i <= temp_n; ++i) {
        while (temp_n % i == 0) {
            factors.push_back(i);
            temp_n /= i;
        }
    }
    if (temp_n > 1) {
        factors.push_back(temp_n);
    }
    if (factors.size() < k) {
        cout << -1 << endl;
        return;
    }
 
    for (int i = 0; i < k - 1; ++i) {
        cout << factors[i] << " ";
    }
    long long last_factor = 1;
    for (size_t i = k - 1; i < factors.size(); ++i) {
        last_factor *= factors[i];
    }
    cout << last_factor << endl;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
 
    return 0;
}
