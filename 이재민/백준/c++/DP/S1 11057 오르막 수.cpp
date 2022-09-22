#include <iostream>
using namespace std;

int dp[1001][10];
int main(){
    int n;
    cin>>n;

    for(int i=0; i<10; i++){
        dp[1][i] = i+1;
    }

    for(int i=2; i<=n; i++){
        dp[i][0] = 1;
        for(int j=1; j<10; j++){
            dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % 10007 ;  
        }
    }

    cout<<dp[n][9]<<endl;

    



    return 0;
}

