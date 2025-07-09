#include <bits/stdc++.h>
using namespace std;

int a[11][11]; // Max size N, M <= 10
int n, m;

int maxPathSum(int i, int j) {
    // Base case: reached bottom-right cell
    if (i == n - 1 && j == m - 1) {
        return a[i][j];
    }

    int right = INT_MIN, down = INT_MIN;

    // Move right
    if (j + 1 < m) {
        right = maxPathSum(i, j + 1);
    }

    // Move down
    if (i + 1 < n) {
        down = maxPathSum(i + 1, j);
    }

    // Return current value + best of right/down
    return a[i][j] + max(right, down);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    cout << maxPathSum(0, 0) << endl;
    return 0;
}
