#include <iostream>
#include <queue>
#include <vector>
using namespace std;



bool locPos(int x, int y, int l, bool visited[][300]){
    if(x < 0 || x >= l) return false;
    if( y < 0 || y >= l) return false;
    if(visited[x][y]==1) return false;

    return true;
}

int bfs(int l, int px, int py, int dx, int dy){
    bool visited[300][300] = {0,};
    int res[l][l] = {0,};
    queue<pair<int, int>> q;
    int cnt = 1;
    q.push({px, py});
    visited[px][py] = true;

    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        //cout<<x<<" "<<y<<endl;
        if(locPos(x+1, y-2, l, visited)){
            visited[x+1][y-2] = true;
            res[x+1][y-2] = res[x][y]+1;
            q.push({x+1, y-2});
        }

        if(locPos(x+2, y-1, l, visited)){
            visited[x+2][y-1] = true;
            res[x+2][y-1] = res[x][y]+1;
            q.push({x+2, y-1});
        }

        if(locPos(x+2, y+1, l, visited)){
            visited[x+2][y+1] = true;
            res[x+2][y+1] = res[x][y]+1;
            q.push({x+2, y+1});
        }

        if(locPos(x+1, y+2, l, visited)){
            visited[x+1][y+2] = true;
            res[x+1][y+2] = res[x][y]+1;
            q.push({x+1, y+2});
        }

        if(locPos(x-1, y+2, l, visited)){
            visited[x-1][y+2] = true;
            res[x-1][y+2] = res[x][y]+1;
            q.push({x-1, y+2});
        }

        if(locPos(x-2, y+1, l, visited)){
            visited[x-2][y+1] = true;
            res[x-2][y+1] = res[x][y]+1;
            q.push({x-2, y+1});
        }

        if(locPos(x-2, y-1, l, visited)){
            visited[x-2][y-1] = true;
            res[x-2][y-1] = res[x][y]+1;
            q.push({x-2, y-1});
        }

        if(locPos(x-1, y-2, l, visited)){
            visited[x-1][y-2] = true;
            res[x-1][y-2] = res[x][y]+1;
            q.push({x-1, y-2});
        }

        if(visited[dx][dy]==true) break;
    }
    

    return res[dx][dy];
}

int main(){
    int t;
    cin>>t;

    for(int i=0; i<t; i++){
        int l, px, py, dx, dy;
        cin>>l>>px>>py>>dx>>dy;
        cout<<bfs(l, px, py, dx, dy)<<endl;
    }

    return 0;
}