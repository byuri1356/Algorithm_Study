#include <iostream>
using namespace std;

int dp[101][100001]; //물품 seq, 무게
int w[101]; //무게
int v[101]; //가치

void bagdp(int n, int maxw){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=maxw; j++){
            if(w[i] <= j){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
}

int main(){
    int n, maxw;
    int max = 0;
    cin>>n>>maxw;

    for(int i=1; i<=n; i++){
        cin>>w[i]>>v[i];
    }
    bagdp(n, maxw);

    

    cout<<dp[n][maxw]<<endl;



    return 0;
}