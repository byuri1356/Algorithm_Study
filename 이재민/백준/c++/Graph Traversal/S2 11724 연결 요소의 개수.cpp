#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v[1001];
bool visited[1001];
int cnt;

void dfs(int s, int seq){
    visited[s] = true;
    if(seq == 0) cnt++;
    for(int i=0; i<v[s].size(); i++){
        int x = v[s][i];
        if(visited[x]==0){

            dfs(x, seq+1);
            
        }
        
    }
}

int main(){
    int n, m, s;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int x, y;
        cin>>x>>y;
        if(i==0) s = x;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=1; i<=n; i++){
        sort(v[i].begin(), v[i].end());
    }    

    for(int i=1; i<=n; i++){
        if(visited[i]==0)
            dfs(i, 0);
    }
    
    
    cout<<cnt<<endl;
    

    

    return 0;
}