#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
vector<int> c;
bool visited[10001];

void NM(int n, int m){
    if(c.size()==m){
        for(int i=0; i<c.size(); i++){
            cout<<c[i]<<" ";
        }
        cout<<"\n";
        return ;
    }


    for(int i=0; i<n; i++){
        int x = v[i];
        if(visited[x]==1) continue;
        
        visited[x] = 1;
        c.push_back(x);
        NM(n, m);
        c.pop_back();
        visited[x] = 0;        
    }
}

int main(){
    int n, m;
    cin>>n>>m;

    for(int i=0; i<n; i++){
        int input;
        cin>>input;
        v.push_back(input);
    }
    sort(v.begin(), v.end());

    NM(n, m);

    return 0;
}