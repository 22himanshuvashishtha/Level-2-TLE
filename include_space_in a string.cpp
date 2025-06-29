#include <bits/stdc++.h>
using namespace std;

long long sumo(int n, string s, long long count = 0) {
    if (n == s.length()) {
        return count;
    }
    
    char c = tolower(s[n]);
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        return sumo(n + 1, s, count + 1);
    } else {
        return sumo(n + 1, s, count);
    }
}

int main() {
    string s;
    getline(cin, s); 
    cout << sumo(0, s);
    return 0;
}
