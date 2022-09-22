#include <iostream>
using namespace std;

long long dp[91];

long long Pinary(int n){
    if(n==1 || n==2) return 1;
    
    if(dp[n]!=0) return dp[n];

    return dp[n] = Pinary(n-1) + Pinary(n-2);
}

int main(){
    int n;
    cin>>n;

   

    cout<<Pinary(n)<<"\n";

    return 0;
}