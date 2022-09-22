#include <iostream>
using namespace std;

int arr[1000001];

void initArr(){
    for(int i=2; i<=1000000; i++){
        arr[i] = i;
    }
}

void makePrime(){
    for(int i=2; i<=1000000; i++){
        if(arr[i]==0) continue;
        for(int j = i+i; j<=1000000; j+=i){
            arr[j] = 0;
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    int n;
    initArr();
    makePrime();
    while(cin>>n){
        if(n==0) break;
        bool check = 0;
        int x=0, y=0;
        for(int i=n-1; i>=2; i--){
            if(arr[i] + arr[n-i] == n){
                x = n-i; y = i;
                check=1;
                break;
            }
        }
        if(check==0) cout<<"Goldbach's conjecture is wrong."<<"\n";
        else cout<<n<<" = "<<x<<" + "<<y<<"\n";
    }

    return 0;
}