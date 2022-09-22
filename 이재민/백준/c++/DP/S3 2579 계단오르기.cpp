#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

void dp(int n){
    for(int i=1; i<n; i++){
        if(i==1) v[i] = v[i] + v[i-1];
        else if(i==2) v[i] = v[i] + v[i-1] + v[i-2];
    }
}

int main(){
    int n;
    
    cin>>n;

    for(int i=0; i<n; i++){
        int input;
        cin>>input;
        v.push_back(input);
    }



    return 0;
}