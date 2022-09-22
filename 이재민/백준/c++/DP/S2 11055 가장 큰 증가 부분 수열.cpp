#include <iostream>
using namespace std;

int arr[1001];
int dp[1001];

int LS(int n){
    int m = dp[0];
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[i], dp[j] + arr[i]);
                if(dp[i] > m) m = dp[i];
            }
        }
    }
    return m;
}

int main(){
    int n;

    cin>>n;
    
    for(int i=0; i<n; i++){
        cin>>arr[i];
        dp[i] = arr[i];
    }

    cout<<LS(n)<<"\n";
    
    return 0;

}