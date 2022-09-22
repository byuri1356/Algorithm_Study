#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v[2000];
bool visited[2000];

bool check;

void _init(int n){
    check = 0;
    for(int i=0; i<n; i++){
        visited[i] = 0;
    }
}

void dfs(int c, int s){
    if(c==5){
        check = 1;
        return ;
    }
    

    for(int i=0; i<v[s].size(); i++){
        int x = v[s][i];
        if(visited[x]==0){
            visited[x] = 1;
            dfs(c+1, x);
            visited[x] = 0;
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int x, y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    for(int i=0; i<n; i++){
        visited[i] = 1;
        dfs(1, i);
        if(check==1) break;
        _init(n);
    }
    
    if(check == 1) cout<<1<<"\n";
    else cout<<0<<"\n";


    
    return 0;
}