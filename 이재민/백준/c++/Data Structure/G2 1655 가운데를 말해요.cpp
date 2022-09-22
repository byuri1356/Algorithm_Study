#include <iostream>
#include <queue>
#include <vector>
using namespace std;

priority_queue<int, vector<int>, greater<int>> min_h;
priority_queue<int> max_h;

void swap(){
    int temp = min_h.top();
    min_h.pop();
    min_h.push(max_h.top());
    max_h.pop();
    max_h.push(temp);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, input;
    
    vector<int> res;
    cin>>n;
    //max_h와 min_h의 크기를 비슷하게 두면서 가운데값을 출력
    for(int i=0; i<n; i++){
        cin>>input;
        //max_h이 min_h보다 크게 & max_h최대 출력(가운데값 중 최소값을 출력해야 하기 때문)
        if(max_h.empty()){
            max_h.push(input);
            res.push_back(input);
        }
        else{
            if(max_h.size() == min_h.size()){
                max_h.push(input);
                if(max_h.top() > min_h.top()){
                    swap();
                }
                res.push_back(max_h.top());
            }

            else if(max_h.size() > min_h.size()){
                min_h.push(input);
                if(max_h.top() > min_h.top()){
                    swap();
                }
                res.push_back(max_h.top());
            }
        }
    }
    

    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<"\n";

    }

    return 0;
}