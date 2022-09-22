#include <iostream>
#include <vector>
using namespace std;

vector<int> c;

void NM(int n, int m){
    if(c.size()==m){
        for(int i=0; i<c.size(); i++){
            cout<<c[i]<<" ";
        }
        cout<<"\n";
        return ;
    }

    for(int i=1; i<=n; i++){
        c.push_back(i);
        NM(n, m);
        c.pop_back();
    }
}

int main(){
    int n, m;
    cin>>n>>m;

    NM(n, m);

    return 0;
}