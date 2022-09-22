#include <iostream>

using namespace std;

double dp[21][3001];
//float win, lose, draw;


void tear(double win, double lose, double draw){
    for(int i=1; i<=20; i++){
        for(int j=1000; j<=2950; j+=50){
            dp[i][j-50] += dp[i-1][j] * lose;
            dp[i][j] += dp[i-1][j] * draw;
            dp[i][j+50] += dp[i-1][j] * win;
        }
    }
}



int main(){
    double win, lose, draw;
    double b=0, s=0, g=0, p=0, d=0;
    cin>>win>>lose>>draw;

    dp[0][2000] = 1;
    

    tear(win, lose, draw);

    
    for(int i=1000; i<=3000; i+=50){
        if(i == 3000) d += dp[20][i];
        else if(i >= 2500) p += dp[20][i];
        else if(i >= 2000) g += dp[20][i];
        else if(i >= 1500) s += dp[20][i];
        else b += dp[20][i];
    }

    printf("%.8lf\n%.8lf\n%.8lf\n%.8lf\n%.8lf\n", b,s,g,p,d);

    return 0;
}