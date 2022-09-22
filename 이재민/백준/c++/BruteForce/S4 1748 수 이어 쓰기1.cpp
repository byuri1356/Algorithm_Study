#include <iostream>
#include <string>
using namespace std;

int main(){
    string s = "";
    int res = 0;
    int n;

    cin>>n;

    for(int i=1; i<=n; i*=10){
        res += (n - i) + 1;
        cout<<res<<endl;
        
    }

    //cout<<res<<endl;

    return 0;
}