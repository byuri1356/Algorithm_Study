#include <iostream>
#include <vector>
using namespace std;

vector<int> c;

void NM(int idx, int n, int m){
    if(c.size()==m){
        for(int i=0; i<c.size(); i++){
            cout<<c[i]<<" ";
        }
        cout<<"\n";
        return ;
    }

    for(int i=idx; i<=n; i++){
        c.push_back(i);
        NM(i, n, m);
        c.pop_back();
    }
}

int main(){
    int n, m;
    cin>>n>>m;

    NM(1, n, m);

    return 0;
}