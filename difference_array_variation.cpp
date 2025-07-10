#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k, q;
    cin >> n >> k >> q;
    
    const int MAX_TEMP = 200000;
    vector<int> diff(MAX_TEMP + 2, 0);
    
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        diff[l]++;
        if (r + 1 <= MAX_TEMP) {
            diff[r + 1]--;
        }
    }
    
    vector<int> recipeCount(MAX_TEMP + 1, 0);
    int current = 0;
    for (int i = 1; i <= MAX_TEMP; ++i) {
        current += diff[i];
        recipeCount[i] = current;
    }
    
    vector<int> admissible(MAX_TEMP + 1, 0);
    for (int i = 1; i <= MAX_TEMP; ++i) {
        admissible[i] = (recipeCount[i] >= k) ? 1 : 0;
    }
    
    vector<int> prefixAdmissible(MAX_TEMP + 1, 0);
    for (int i = 1; i <= MAX_TEMP; ++i) {
        prefixAdmissible[i] = prefixAdmissible[i - 1] + admissible[i];
    }
    
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << prefixAdmissible[b] - prefixAdmissible[a - 1] << '\n';
    }
    
    return 0;
}
