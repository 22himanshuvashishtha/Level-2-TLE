#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n), so(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        so = v;
        sort(so.begin(), so.end());
        map<int, pair<int,int>> freqOriginal, freqSorted;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) freqOriginal[v[i]].first++;
            else freqOriginal[v[i]].second++;
        }
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) freqSorted[so[i]].first++;
            else freqSorted[so[i]].second++;
        }

        if (freqOriginal == freqSorted)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
