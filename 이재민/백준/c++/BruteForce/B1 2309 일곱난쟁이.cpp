#include <iostream>
using namespace std;

int arr[9];

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void sort7(){
    for(int i=0; i<9; i++){

    }
}

int max(int k){
    int m = 0;
    int idx = 0;
    for(int i=0; i<=k; i++){
        if(arr[i] >= m){
            m = arr[i];
            idx = i;
        } 
    }
    return idx;
}

int main(){
    int sum = 0;
    int sum2 = 0;
    bool check = 0;
    for(int i=0; i<9; i++){
        cin>>arr[i];
        sum += arr[i];
    }
    sum -= 100;

    for(int i=0; i<8; i++){
        for(int j=i+1; j<9; j++){
            if(arr[i] + arr[j] == sum){
                arr[i] = 0; arr[j] = 0;
                check = 1;
                break;
            }
        }
        if(check==1) break;
    }

    for(int i=8; i>=0; i--){
        int idx = max(i);
        swap(arr[i], arr[idx]);
    }

    for(int i=2; i<9; i++){
        cout<<arr[i]<<endl;
    }
    

    return 0;
}