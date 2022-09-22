#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool rcX[10];

int checklen(int n){
    int cnt = 0;
    if(n==0) {
        if(rcX[n]==0) return 1;
    }
    while(n!=0){
        if(rcX[n%10]==1){
            cnt = 0;
            break;
        }
        n /= 10;
        
        cnt++;
    }

    return cnt;
}

int main(){
    int n, m;

    cin>>n>>m;

    for(int i=0; i<m; i++){
        int input;
        cin>>input;
        rcX[input] = 1;
    }

    int cnt = abs(n - 100);

    if(cnt==0) cout<<0<<endl;

    else{
        for(int i=0; i<=999999; i++){
            int len = checklen(i);
            if(len){
                cnt = min(cnt, len + abs(n-i));
            }
        }
        cout<<cnt<<endl;
    }

    


    return 0;
}