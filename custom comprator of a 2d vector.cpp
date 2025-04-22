#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    int n = 5;
    vector<vector<string>> v(t, vector<string>(n));
    vector<pair<pair<int, string>, int>> data; 
    for (int i = 0; i < t; i++) {
        int total = 0;
        string name;
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
            if (j == 0) {
                name = v[i][j];
            } else {
                total += stoi(v[i][j]);
            }
        }
        data.push_back({{total, name}, i});
    }

    sort(data.begin(), data.end(), [&](auto &a, auto &b) {
        int totalA = a.first.first;
        int totalB = b.first.first;
        string nameA = a.first.second;
        string nameB = b.first.second;

        if (abs(totalA - totalB) > 10) {
            return totalA > totalB;  
        } else {
            return nameA < nameB;    
        }
    });

    for (auto &entry : data) {
        int total = entry.first.first;
        int idx = entry.second;
        cout << v[idx][0] << " " << total << " ";
        for (int j = 1; j < 5; j++) {
            cout << v[idx][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
