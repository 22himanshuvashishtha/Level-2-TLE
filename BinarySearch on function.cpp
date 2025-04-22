#include <bits/stdc++.h>
using namespace std;

long long cardsRequired(int h) {
    return (3LL * h * h + h) / 2;
}

int getMaxHeight(int n) {
    int l = 1, r = 1e5, ans = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (cardsRequired(mid) <= n) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int count = 0;
        while (n >= 2) {
            int height = getMaxHeight(n);
            if (height == 0) break;
            n -= cardsRequired(height);
            count++;
        }
        cout << count << endl;
    }
    return 0;
}
