#include <bits/stdc++.h>
using namespace std;

void solve() {
    int t;
    cin >> t;
    vector<int> v(t);
    for (int i = 0; i < t; i++) {
        cin >> v[i];
    }

    vector<int> ans(t);
    stack<int> st;

    for (int i = t-1; i>0; i--) {
        while (!st.empty() && st.top() >= v[i]) {
            st.pop();
        }

        if (st.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = st.top();
        }

        st.push(v[i]);
    }

    for (int i = 0; i < t; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
