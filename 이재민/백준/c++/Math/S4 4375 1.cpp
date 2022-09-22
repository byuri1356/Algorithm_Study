#include <iostream>
using namespace std;

int main(){
    int n;

    while(cin>>n){
        int t = 0;
        int count = 0;

        while(1){
            t = t * 10 + 1;
            t %= n;
            if(t==0)
                break;
            count++;
        }
        cout<<count+1<<endl;
    }

    return 0;
}