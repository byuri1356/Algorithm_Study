#include <iostream>
using namespace std;

char color[101][101];
int visited[101][101];
int rx[4] = {1, 0, 0, -1};
int ry[4] = {0, 1, -1, 0};

bool locPos(int x, int y, int n){
    if(x<0 || x>=n) return false;
    if(y<0 || y>=n) return false;
    if(visited[x][y]) return false;

    return true;
}

void dfs(int x, int y, int n, int k){
    visited[x][y] = k; //방문표시 및 구역 번호

    for(int i=0; i<4; i++){ //상하좌우
        int nx = x + rx[i];
        int ny = y + ry[i];
        if(locPos(nx, ny, n)){
            if(color[x][y] == color[nx][ny]) // 같은 color에 같은 구역번호 부여
                dfs(nx, ny, n, visited[x][y]);
        }
    }
}

int main(){
    int n;
    int m=0, w_m=0;
    int cnt = 0;
    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>color[i][j];
            
        }
    }

    //색약 아닌 사람 dfs 수행
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j]) //방문X = 다른 색깔
                dfs(i, j, n, ++cnt); 
        }
    }

    //색약이 아닌 사람의 최대값 & 색약에 맞게 배열 설정 & 방문값 초기화 
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visited[i][j] > m) m = visited[i][j];
            visited[i][j] = 0;
            if(color[i][j] == 'G') color[i][j] = 'R';
        }

    }

    //색약 dfs 수행
    cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j])
                dfs(i, j, n, ++cnt); 
        }
    }

    //색약 최대값
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visited[i][j] > w_m) w_m = visited[i][j];
        }
    }

    cout<<m<<" "<<w_m<<"\n";

    return 0;

}