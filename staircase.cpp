#include <bits/stdc++.h>
using namespace std;

long long sumo(long long n,long long m) {
    if (m==n) return 1;
    if (m<n) return 0;      
    return sumo(n,m-1)+sumo(n,m-2)+sumo(n,m-3); 
}

int main() {
    long long n,m;
    cin >>n>>m;
    cout<<sumo(n,m);
    return 0;
}
