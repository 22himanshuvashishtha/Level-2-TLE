#include <bits/stdc++.h>
using namespace std;

long long sumo(long long m) {
    if (m==1) return 0;
    if (m==2) return 1;      
    return sumo(m-1)+sumo(m-2); 
}

int main() {
    long long n;
    cin >>n;
    cout<<sumo(n);
    return 0;
}
