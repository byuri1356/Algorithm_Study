#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define Max_d 2147483647

vector<int> res;

void ts(int arr[][2], vector<int> p, int n, int t){
    if(t>=n){
        int sum=0;
        for(int i=0; i<p.size(); i++){
            sum += arr[p[i]][1];
        }
        
        res.push_back(sum);
    }

    else{
        int w = t + arr[t][0];
        if(w <= n)
            p.push_back(t);
        ts(arr, p, n, w);

        if(w+arr[w+1][0]<=n){
            ts(arr, p, n, w+1);
        }
    }
    
}


int main(){
    int n;
    cin>>n;
    int arr[n][2] = {0,};
    vector<int> pick;
    res.push_back(0);
    for(int i=0; i<n; i++){
        for(int j=0; j<2; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<n; i++){
        ts(arr, pick, n, i);
    }
    int max_res = *max_element(res.begin(), res.end());
    
    cout<<max_res<<endl;

    return 0;
}