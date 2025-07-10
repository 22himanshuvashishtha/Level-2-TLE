#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin >> n;
    ll c;
    cin >> c;
    vector<ll> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    
    vector<ll> start(c), end(c);
    for(ll i = 0; i < c; i++) {
        cin >> start[i] >> end[i];
        start[i]--; // Convert to 0-based indexing
        end[i]--;   // Convert to 0-based indexing
    }
    
    vector<ll> diff(n + 1, 0); 
    for(int i = 0; i < c; i++) {
        diff[start[i]] += 1;
        if(end[i] + 1 < n) {
            diff[end[i] + 1] -= 1;
        }
    }
    
    for(int i = 1; i < n; i++) {
        diff[i] += diff[i - 1];
    }
    sort(diff.begin(), diff.begin() + n);
    sort(v.begin(), v.end());
    
    ll answer = 0;
    for(int i = 0; i < n; i++) {
        answer += (diff[i] * v[i]);
    }
    cout << answer << endl;
}

int main() {
    solve();
    return 0;
}
