#include <iostream>
using namespace std;

int gcd(int a, int b){
    int c;
    while(b!=0){
        c = a%b;
        a = b;
        b = c;
    }

    return a;
}

int lcm(int a, int b){
    return (a * b) / gcd(a, b);
}

int main(){
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        int M, N, x, y;
        bool check = 0;
        cin>>M>>N>>x>>y;
        int t = lcm(M, N);

        for(int i=x; i<=t; i+=M){
           if(i%N == y){
                cout<<i<<endl;
                check = 1;
                break;
           }

           else if(i%N==0){
                if(N == y){
                    cout<<i<<endl;
                    check = 1;
                    break;
                }
           }
        }

        if(check==0) cout<<-1<<endl;


    }


    return 0;
}