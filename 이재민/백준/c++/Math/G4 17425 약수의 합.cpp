#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    int arr[100001] = {0,};
    cin>>t;

    for(int i=1; i<=100001; i++){
        for(int j=1; j<=i; j++){
            arr[i] += j * (i/j);
        }
    }

    for(int i=0; i<t; i++){
        long long res = 0;
        int n;
        cin>>n;
        
        cout<<arr[i]<<"\n";

    }
    return 0;
}