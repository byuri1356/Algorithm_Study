#include <iostream>
using namespace std;

int dp[1001];

int tile(int n){
    if(n==1) return 1;
    if(n==2) return 3;
    if(dp[n]!=0) return dp[n];

    return dp[n] = (tile(n-2) * 2 + tile(n-1)) % 10007 ;
}

int main(){
    int n;

    cin>>n;

    cout<<tile(n)<<"\n";

    return 0;
}