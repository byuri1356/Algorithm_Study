#include <iostream>
using namespace std;

//Bottom-up
/*
pair<int, int> p[41];

void fibo(int n){
    if(n==0 || n==1) {
        cout<<p[n].first<<" "<<p[n].second<<endl;
        return ;
    }
    for(int i=2; i<=n; i++){
        p[i].first = p[i-1].first + p[i-2].first;
        p[i].second = p[i-1].second + p[i-2].second;
    }
    cout<<p[n].first<<" "<<p[n].second<<endl;
}

int main(){
    int t;
    p[0].first = 1; p[0].second=0;
    p[1].first = 0; p[1].second=1;
    
    cin>>t;
    for(int i=0; i<t; i++){
        int n;
        cin>>n;
        fibo(n);
        
    }

    return 0;

}
*/

//Top-down
pair<int, int> p[41];

pair<int, int> fibo(int n){
    if(n==0) return make_pair(1, 0);
    else if(n==1) return make_pair(0, 1);

    if(p[n].first>0 && p[n].second>0)
        return make_pair(p[n].first, p[n].second);

    return p[n] = make_pair(fibo(n-1).first + fibo(n-2).first, fibo(n-1).second + fibo(n-2).second);
}

int main(){
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        int n;
        cin>>n;
        cout<<fibo(n).first<<" "<<fibo(n).second<<endl;
    }

    return 0;

}



