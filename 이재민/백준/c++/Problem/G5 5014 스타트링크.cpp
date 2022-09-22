#include <iostream>
#include <queue>
using namespace std;

int snl[1000001];
bool visited[1000001];

bool locPos(int x, int f){
    if(x<1 || x>f) return false;
    if(visited[x]) return false;
    return true;
}

void bfs(int f, int s, int g, int u, int d){
    queue<int> q;
    q.push(s);
    snl[s] = 0;
    visited[s] = true;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        if(locPos(x-d, f)){
            visited[x-d] = true;
            snl[x-d] = snl[x] + 1;
            q.push(x-d);
        }
        if(locPos(x+u, f)){
            visited[x+u] = true;
            snl[x+u] = snl[x] + 1;
            q.push(x+u);
        }

        if(snl[g]) break;
    }
}

int main(){
    int f, s, g, u, d;
    //총 층수, 현재 있는 층수, 가야하는 층수, 위로 u층, 아래로 d층 
    cin>>f>>s>>g>>u>>d;

    if(s==g) cout<<0<<"\n";
    else{
        bfs(f, s, g, u, d);

        if(snl[g]==0) cout<<"use the stairs"<<"\n";
        else cout<<snl[g]<<"\n";
    }
    return 0;
}
