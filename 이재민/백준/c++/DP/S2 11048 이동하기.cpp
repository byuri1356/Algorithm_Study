#include <iostream>
#include <queue>
using namespace std;

int map[1000][1000];
int candy[1000][1000];
bool visited[1000][1000];
queue<pair<int, int>> q;

bool vpos(int x, int y, int n, int m){
    if(x>=n || y>=m) return false;
    return true;
}

void bfs(int n, int m){
    candy[0][0] = map[0][0];
    q.push({0,0});
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(vpos(x+1, y, n, m)){
            
            if(visited[x+1][y]==0){
                visited[x+1][y] = 1;
                q.push({x+1, y});
            } //방문을 안했을때 
            1 2 3 4
            1 0 0 5
            9 9 7 6
            if(candy[x][y] + map[x+1][y] > candy[x+1][y]){
                candy[x+1][y] = candy[x][y] + map[x+1][y];
            }
            //q.push({x+1, y});
        }

        if(vpos(x, y+1, n, m)){
            
            if(visited[x][y+1]==0){
                visited[x][y+1] = 1;
                q.push({x, y+1});
            }
            
            if(candy[x][y] + map[x][y+1] > candy[x][y+1]){
                candy[x][y+1] = candy[x][y] + map[x][y+1];
            }
            //q.push({x, y+1});
        }

        if(vpos(x+1, y+1, n, m)){
            if(visited[x+1][y+1]==0){
                visited[x+1][y+1] = 1;
                q.push({x+1, y+1});
            }
            if(candy[x][y] + map[x+1][y+1] > candy[x+1][y+1]){
                candy[x+1][y+1] = candy[x][y] + map[x+1][y+1];
            }
            //q.push({x+1, y+1});//메모리초과
        }
    }
}

int main(){
    int n, m;
    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>map[i][j];
        }
    }
    bfs(n, m);

    cout<<candy[n-1][m-1]<<endl;
    /*
    cout<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<candy[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    return 0;
}