#include <iostream>
using namespace std;

char arr[50][50];

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int rowCount(int n){
    int res = 0;
    for(int i=0; i<n; i++){
        int cnt = 1;
        for(int j=0; j<n-1; j++){
            if(arr[i][j] == arr[i][j+1]){
                cnt++;
            }
            else{
                res = max(res, cnt);
                cnt = 1;
            }
        }
        res = max(res, cnt);
    }
    return res;
}
int colCount(int n){
    int res = 0;
    for(int i=0; i<n; i++){
        int cnt = 1;
        for(int j=0; j<n-1; j++){
            if(arr[j][i] == arr[j+1][i]){
                cnt++;
            }
            else{
                res = max(res, cnt);
                
                cnt = 1;
            }
        }
        res = max(res, cnt);
    }
    return res;
}

int main(){
    int n;
    int res = 0;
    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    res = max(res, rowCount(n));
    res = max(res, colCount(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1; j++){
            swap(arr[i][j], arr[i][j+1]);
            res = max(res, rowCount(n));
            res = max(res, colCount(n));
            swap(arr[i][j], arr[i][j+1]);
            
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1; j++){
            swap(arr[j][i], arr[j+1][i]);
            res = max(res, rowCount(n));
            res = max(res, colCount(n));
            swap(arr[j][i], arr[j+1][i]);
        }
    }

    cout<<res<<endl;
    return 0;
}