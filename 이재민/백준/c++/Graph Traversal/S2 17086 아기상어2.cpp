#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 99999999;

int map[50][50];
int arr[50][50];
bool visited[50][50];
vector<pair<int, int>> shark;
queue<pair<int, int>> q;
int max_dist;

int rx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int ry[8] = {0, 1, 1, 1, 0, -1, -1, -1};

bool locPos(int x, int y, int n, int m){
    if(x < 0 || x >= n) return false;
    if(y < 0 || y >= m) return false;
    if(visited[x][y] == 1) return false;
    return true;
}

void bfs(int n, int m){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<8; i++){
            int nx = x + rx[i];
            int ny = y + ry[i];
            if(locPos(nx, ny, n, m)){
                visited[nx][ny] = 1;
                if(map[nx][ny] != 1){
                    map[nx][ny] = map[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

}

int main(){
    int n, m;
    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>map[i][j];
            if(map[i][j]==1) q.push({i, j});
        }
    }   

    bfs(n, m);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] > max_dist) max_dist = map[i][j];
        }
    }   

    cout<<max_dist-1<<endl;

    return 0;
}