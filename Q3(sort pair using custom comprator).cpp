#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    vector<string>s={"Hussien", "Atef", "Karemo","Ezzat"};
    while(t--){
        int n=4;
        vector<int>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        vector<pair<int,int>>m;
        for(int i=0;i<n;i++){
            m.push_back({i,v[i]});
        }
        sort(m.begin(), m.end(), [](pair<int,int> a, pair<int,int> b) {
        return a.second > b.second;
        });
        int a=m[0].first;
        int b=m[1].first;
        cout<<s[a]<<" "<<s[b]<<endl;
    }
    return 0;
}
