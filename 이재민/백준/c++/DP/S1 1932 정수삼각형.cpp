#include <iostream>
using namespace std;

int dp[125251];
int level[125251];

int triangle(int ilv){
    int m = dp[1];
    for(int i=2; i<=ilv; i++){
        if(level[i - level[i]] != level[i]-1){
            dp[i] += dp[i - level[i] + 1];
            if(dp[i] > m) m = dp[i];
        }
    
        else if(level[i - level[i] + 1] != level[i]-1){
            dp[i] += dp[i - level[i]] ;
            if(dp[i] > m) m = dp[i];
        }

        else{
            dp[i] += max(dp[i - level[i] + 1], dp[i - level[i]]);
            if(dp[i] > m) m = dp[i];
        }
    }

    return m;
}


int main(){
    int n;
    int l = 0, lv = 1;
    int ilv = 0;

    cin>>n;

    for(int i=1; i<=n; i++){
        ilv += i;
    }

    for(int i=1; i<=ilv; i++){
        cin>>dp[i];
        level[i] = lv;
        l++;
        if(l==lv){
            l=0;
            lv++;
        }
    }

    cout<<triangle(ilv)<<endl;

    return 0;
}