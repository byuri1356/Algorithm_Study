#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    long long res = 0;
    cin>>n;

    for(int i=1; i<=n; i++){
        res += i *(n / i);
    }

    cout<<res<<endl;

    return 0;
}