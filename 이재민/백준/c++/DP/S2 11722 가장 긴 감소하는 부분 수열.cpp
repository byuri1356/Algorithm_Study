#include <iostream>
using namespace std;

#define INF 9999999

int arr[1001];
int dp[1001];

int LMS(int n){
    int m = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[i] < arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
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
        dp[i] = 1;
    }

    cout<<LMS(n)<<"\n";
    
    return 0;

}