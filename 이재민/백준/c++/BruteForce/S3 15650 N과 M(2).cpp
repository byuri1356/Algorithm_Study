#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

void combination(int idx, int count, int m, int n){

    if(count==m){
        for(int i=0; i<v.size(); i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        return ;
    }

    for(int i=idx; i<=n; i++){
        v.push_back(i);
        combination(i+1, count+1, m, n);
        v.pop_back();
    }
}

int main(){
    int n, m;
    cin>>n>>m;

    combination(1, 0, m, n);

    return 0;
}