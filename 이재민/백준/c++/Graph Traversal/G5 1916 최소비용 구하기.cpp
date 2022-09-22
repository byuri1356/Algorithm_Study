#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 2147483647
// (이동하려는 노드 번호와 가중치, 양의 가중치)
vector<pair<int, int>> v[1001];
int cost[1001];
//같은 방향의 여러 노선
//방향 그래프

void dijkstra(int s){
    priority_queue<pair<int, int>> q; //cost, node 
    q.push({0, s});
    cost[s] = 0;
    while(!q.empty()){
        //최소힙을 구성하기 위해서 음수로 값을 저장하고 음수로 값을 가져온다
        //ex) 5 4 3 2 1 -> -1 -2 -3 -4 -5(저장) -> -top = 1 (최소값);
        int d = -q.top().first;
        int cur = q.top().second;
        
        q.pop();

        //노드 탐색 중 이미 더 짧은 거리가 들어가 있으면 Skip
        //ex) 2->3의 거리가 5 >4->3의 거리가 4일경우
        // 4->3이 2->3보다 큐에 먼저 들어가 4의 값을 저장하기 때문에
        // 어차피 인접노드들을 갱신할 필요가 없음 (최소값 형성이 안되기 떄문)
        if(cost[cur] < d) continue;

        for(int i=0; i<v[cur].size(); i++){ //현재 노드의 값을 이용해서 인접 노드의 가중치를 계산 (최소값)
            int nxt = v[cur][i].first; //다음 노드 (현재 노드가 가리키는 i번째 노드, 인접노드)
            int nxt_d = cost[cur] + v[cur][i].second; //인접 노드의 가중치
            if(nxt_d< cost[nxt]){
                cost[nxt] = nxt_d;
                q.push({-cost[nxt], nxt});
            }
        }
    }
}

int main(){
    int n, m;
    int s, d;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int x, y, c;
        cin>>x>>y>>c;
        v[x].push_back({y, c});
        //v[y].push_back({x, c});
    }
    
    for(int i=1; i<=n; i++) cost[i] = INF;
    cin>>s>>d;
    dijkstra(s);

    //for(int i=1; i<=n; i++) cout<<cost[i]<<endl;
    //cout<<endl;
    cout<<cost[d]<<endl;
    
    return 0;
}