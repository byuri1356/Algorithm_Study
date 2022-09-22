#include <iostream>
#include <vector>
#include <queue>
using namespace std;

char position[6][6];
int res = 0;
bool visit[26];
vector<int> com;//조합된 숫자 벡터

bool locPos(int x, int y, int arr[][6], bool visited[][6]){
    if(x<0 || y<0 || x>5 || y>5) return false; 
    if(arr[x][y]==0 || visited[x][y]==1) return false; 
    return true;
}

//7개가 연결이 되어있나?
bool linked(vector<pair<int, int>> v){
    int arr[6][6] = {0,}; //전부 벽으로 초기화
    bool visited[6][6] = {0,};
    int count = 0; //연결된 개수를 셈  
    queue<pair<int, int>> q;

    //조합에서 뽑은 7개를 1로 만들어 갈 수 있는 경로로 만들어줌
    for(int i=0; i<v.size(); i++){
        int x = v[i].first; int y = v[i].second;
        arr[x][y] = 1; 
    }
    q.push({v[0].first, v[0].second});

    while(!q.empty()){
        int x = q.front().first; int y = q.front().second;
        q.pop();
        if(locPos(x+1, y, arr, visited)){
            visited[x+1][y] = 1;
            count++;
            q.push({x+1, y});
        }
        if(locPos(x-1, y, arr, visited)){
            visited[x-1][y] = 1;
            count++;
            q.push({x-1, y});
        }
        if(locPos(x, y+1, arr, visited)){
            visited[x][y+1] = 1;
            count++;
            q.push({x, y+1});
        }
        if(locPos(x, y-1, arr, visited)){
            visited[x][y-1] = 1;
            count++;
            q.push({x, y-1});
        }
    }

    if(count<7) return false; //link failure
    return true; 
}

//greater than or equal to 4(이다솜파)
bool S_GE4(vector<pair<int, int>> v){
    int count = 0;
    for(int i=0; i<v.size(); i++){
        int x = v[i].first; int y = v[i].second;
        if(position[x][y] == 'S') count++;
    }
    if(count<4) return false;
    return true;
}


void princess(vector<int> p){
    vector<pair<int, int>> v;
    for(int i=0; i<p.size(); i++){
        int m = p[i]/5;
        if(p[i]%5==0) v.push_back({m, 5});
        else v.push_back({m+1, p[i]%5});
    }

    if(linked(v) && S_GE4(v)) res++;
}

void combi(int idx, int cnt){
    //p에 r개만큼 담은경우
    if(cnt==7){  
        princess(com);
        return ;
    }
   

    //처음 6에서 7을 호출해서 골라내고 이후 반복문에서 8을 호출
    for(int i=idx; i<=25; i++){ 
        com.push_back(i);
        combi(i+1, cnt+1); 
        com.pop_back();
    }
}

    

int main(){
    vector<int> vv;
    vector<int> p(7);
    for(int i=1; i<=5; i++){
        for(int j=1; j<=5; j++){
            cin>>position[i][j];
        }
    }
    for(int i=1; i<=25; i++) vv.push_back(i);

    combi(1, 0);

    cout<<res<<endl;

    return 0;
}