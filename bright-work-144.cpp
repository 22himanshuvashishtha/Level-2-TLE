#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    set<int>s;
    for(int i=0;i<n;i++){
        s.insert(v[i]);
    }
    cout<<s.size()<<endl;
    return 0;
}
