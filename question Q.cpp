#include <bits/stdc++.h>
using namespace std;

long long sumo(long long N,int count) {
    if (N<=1) return count;      
    else if(N%2==0){
        return sumo(N/2,count+1);
    }else{
        return sumo(3*N+1,count+1);
    } 
}

int main() {
    long long N;
    cin >> N;
    long long sum=0;
    sum=sumo(N,1);
    cout<<sum<<endl;
    return 0;
}
