#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int arr[100001];
bool visited[100001];
int path[100001];

vector<int> res;

bool rangeCheck(int x, int n){
    if(x<0) return false;
    if(x>100000) return false;
    if(x==n) return false;
    return true;
}

void bfs(int n, int k){
    queue<int> q;
    int sec = 0;
    visited[n]=1;
    q.push(n);

    while(!q.empty()){
        int x = q.front();
        q.pop();
        

        if(rangeCheck(x-1, n)){
            if(visited[x-1]==0){
                arr[x-1] = arr[x] + 1;
                visited[x-1] = 1;
                q.push(x-1);
                path[x-1] = x;
            }
            else{
                if(arr[x-1] > arr[x]+1){
                    arr[x-1] = arr[x]+1;
                    q.push(x-1);
                }   
            }
        }

        if(rangeCheck(x+1, n)){
            if(visited[x+1]==0){
                arr[x+1] = arr[x] + 1;
                visited[x+1] = 1;
                q.push(x+1);
                path[x+1] = x;
            }
            if(arr[x+1] > arr[x]+1){
                arr[x+1] = arr[x]+1;
                q.push(x+1);
            }   
        }

        if(rangeCheck(x*2, n)){
            if(visited[2*x]==0){
                arr[2*x] = arr[x] + 1;
                visited[2*x] = 1;
                q.push(2*x);
                path[2*x] = x;
            }
            else{
                if(arr[2*x] > arr[x]+1){
                    arr[2*x] = arr[x]+1;
                    q.push(2*x);
                }   
            }
        }
        
    }

}

int main(){
    int n, k;
    cin>>n>>k;

    if(n==k){
        res.push_back(n);
        cout<<0<<endl;
    }
    else{
    bfs(n, k);

    cout<<arr[k]<<endl;
    res.push_back(k);
    int i = k;
    
    while(1){
        if(path[i] == n) {
            res.push_back(n);
            break;
        }

        else{
            res.push_back(path[i]);
            i = path[i];
            
        }
    }
    }
    for(int i=res.size()-1; i>=0; i--){
        cout<<res[i]<<" ";
    }
    return 0;
}