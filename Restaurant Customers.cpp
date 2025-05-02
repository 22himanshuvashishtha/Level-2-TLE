#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    map<int,int>m;
    while(n--){
        int a,b;
        cin>>a>>b;
            m[a]++;
            m[b]--;
    }     
    int log=0,ans=0;      
    for(auto [aadmi,total] :m){
        log+=total;
        ans=max(ans,log);
    }
    cout<<ans;
}
