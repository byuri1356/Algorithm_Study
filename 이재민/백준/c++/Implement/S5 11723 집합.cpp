#include <iostream>
using namespace std;

#define MAX 21

class SetIm{
private:
    int arr[MAX];
    int idx;

public:
    SetIm(){
        idx = 0;
        for(int i=1; i<=20; i++){
            arr[i] = 0;
        }
    }
    
    ~SetIm(){}

    void add(int x){
        if(arr[x]==0){
            arr[x] = x;
        }
    }

    void remove(int x){
        if(arr[x]!=0){
            arr[x] = 0;
        }
    }

    bool check(int x){
        return arr[x];
    }

    void toggle(int x){
        if(arr[x]==0) arr[x] = x;
        else arr[x] = 0;
    }

    void all(){
        for(int i=1; i<=20; i++)
            arr[i] = i;
    }

    void empty(){
        for(int i=1; i<=20; i++)
            arr[i] = 0;
    }

};

void oper(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    int n;
    SetIm se;
    cin>>n;

    for(int i=0; i<n; i++){
        string s;
        int x;
        cin>>s;

        if(s == "add"){
            cin>>x;
            se.add(x);
        }

        else if(s == "remove"){
            cin>>x;
            se.remove(x);
        }

        else if(s == "check"){
            cin>>x;
            cout<<se.check(x)<<"\n";
        }

        else if(s == "toggle"){
            cin>>x;
            se.toggle(x);
        }

        else if(s == "all"){
            se.all();
        }

        else if(s == "empty"){
            se.empty();
        }
    }
}

int main(){
    oper();

    return 0;
}