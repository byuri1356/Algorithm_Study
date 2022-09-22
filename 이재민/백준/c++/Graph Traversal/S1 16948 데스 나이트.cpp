#include <iostream>
#include <queue>
using namespace std;

int chess[200][200];
bool visited[200][200];
int rx[6] = {-2, -2, 0, 0, 2, 2};
int ry[6] = {-1, 1, -2, 2, -1, 1};

bool locPos(int x, int y, int n){
    if(x<0 || x>=n) return false;
    if(y<0 || y>=n) return false;
    if(visited[x][y]==1) return false;
    return true;
}

void bfs(int r1, int c1, int r2, int c2, int n){
    bool check = 0;
    queue<pair<int, int>> q;
    visited[r1][c1] = 1; 
    q.push({r1, c1});
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<6; i++){
            int a = x + rx[i];
            int b = y + ry[i];
            if(locPos(a, b, n)){
                visited[a][b] = 1;
                chess[a][b] = chess[x][y] + 1;
                q.push({a, b});
            }
        }
    }

    
}

int main(){
    int n;
    int r1, c1, r2, c2;
    cin>>n;
    cin>>r1>>c1>>r2>>c2;

    bfs(r1, c1, r2, c2, n);
    if(chess[r2][c2]==0) cout<<-1<<"\n";
    else cout<<chess[r2][c2]<<"\n";
    
    
    return 0;
}