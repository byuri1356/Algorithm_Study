#include <iostream>
#include <vector>
using namespace std;

vector<int> t;
vector<int> v;
bool visited[9];

void permu(int count, int m){
    if(count==m){
        for(int i=0; i<v.size(); i++){
            cout<<v[i]<<" ";
        }
        cout<<"\n";
    }

    for(int i=0; i<t.size(); i++){
        int x = t[i];
        if(visited[x] == true) continue;

        visited[x] = true;
        v.push_back(x);
        permu(count+1, m);
        v.pop_back();
        visited[x] = false; 
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin>>n>>m;
    
    for(int i=0; i<n; i++){
        t.push_back(i+1);
    }

    permu(0, m);

    return 0;
}