#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> g[1001];
bool dfscheck[1001] = {0,};
bool bfscheck[1001] = {0,};

vector<int> dres;
vector<int> bres;

void dfs(int v){
    dfscheck[v] = true;
    dres.push_back(v);

    for(int i=0; i<g[v].size(); i++){
        int x = g[v][i];
        if(dfscheck[x]==0){
            dfs(x);
        }
    }
}

void bfs(int v){
    bfscheck[v] = true;
    queue<int> q;
    q.push(v);
    bres.push_back(v);

    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i=0; i<g[x].size(); i++){
            int nxt = g[x][i];
            if(bfscheck[nxt]==0){
                bfscheck[nxt] = 1;
                bres.push_back(nxt);
                q.push(nxt);
            }
        }
    }
}

int main(){
    int n, m;
    int v;

    cin>>n>>m>>v;

    for(int i=0; i<m; i++){
        int x, y;
        cin>>x>>y;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    for(int i=1; i<=n; i++){
        sort(g[i].begin(), g[i].end());
    }    
    dfs(v);
    for(int i=0; i<dres.size(); i++)
        cout<<dres[i]<<" ";
    cout<<endl;

    bfs(v);
    for(int i=0; i<dres.size(); i++)
        cout<<bres[i]<<" ";
    cout<<endl;


    return 0;
}