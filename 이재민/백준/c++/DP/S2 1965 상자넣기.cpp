#include <iostream>
using namespace std;

int arr[1000] = {0,};
int res[1000] = {0,};

int dp(int n){
    int max = 1;//최대값 출력

    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            //앞뒤상자 크기 비교 && 갱신을 할지
            if(arr[i] > arr[j] && res[j]+1 > res[i]){
                res[i] = res[j]+1;
                if(max < res[i]) max = res[i];
            }
        }
    }

    return max;

}

int main(){
    int n, max=0;
 
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
        res[i] = 1;
    }

    cout<<dp(n)<<endl;

    return 0;

}