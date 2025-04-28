#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);

        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end(), greater<int>());

        int count = 0;
        unordered_set<int> check; 

        for (int i = 0; i < n; i++) {
            int temp = v[i];
            if (check.find(temp) == check.end()) {
                while (temp % 2 == 0) { 
                    check.insert(temp); 
                    temp = temp / 2;
                    count++;
                }
            }
        }
        cout << count << endl; 
    }
    return 0;
}
