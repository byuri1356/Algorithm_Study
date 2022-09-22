#include <iostream>
#include <vector>
using namespace std;

int arr[10000];
int dp[10000];

int wine(int n){
    int res=0;
    dp[0] = arr[0];
    dp[1] = arr[0] + arr[1];
    dp[2] = max(dp[1], max(arr[0]+arr[2], arr[1]+arr[2]));
    if(n<=3) return dp[n-1];

    for(int i=3; i<n; i++){
        dp[i] = max(arr[i] + dp[i-2], arr[i] + arr[i-1] + dp[i-3]);
        dp[i] = max(dp[i], dp[i-1]);
        if(dp[i] > res) res = dp[i];
    }
    //for(int i=0; i<n; i++) cout<<dp[i]<<" ";

    return res;
}

int main(){
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<wine(n)<<endl;
    

    //for(int i=0; i<n; i++) cout<<dp[i]<<" ";
    return 0;
}