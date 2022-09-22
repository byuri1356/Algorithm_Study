#include <iostream>
using namespace std;

long long dp[1000001];

long long plusx(int n){
    if(n==1) return 1;
    if(n==2) return 2;
    if(n==3) return 4;

    if(dp[n]!=0) return dp[n];

    return dp[n] = (plusx(n-1) + plusx(n-2) + plusx(n-3)) % 1000000009;
}

int main(){
    int t;
    cin>>t;

    for(int i=0; i<t; i++){
        int n;
        cin>>n;
        cout<<plusx(n)<<endl;
    }

    return 0;   
}