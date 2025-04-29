#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }

        unordered_map<int, int> freq;
        for (int x : a) {
            freq[x]++;
        }
        bool flag =false;
        long long totalSwaps = (1LL * N * (N - 1)) / 2;
        for (auto [val, count] : freq) {
            if (count > 1) {
                totalSwaps -= (1LL * count * (count - 1)) / 2;
                flag=true;
            }
        }
        if(flag==true){
            cout << totalSwaps+1 << endl;
        }else
        cout << totalSwaps << endl;
    }
    return 0;
}
