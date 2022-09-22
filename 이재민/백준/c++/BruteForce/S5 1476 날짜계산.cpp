#include <iostream>
using namespace std;

int main(){
    int e, s, m;
    int e1=1, s1=1, m1=1;
    int count = 1;
    cin>>e>>s>>m;

    while(!(e==e1 && s==s1 && m==m1)){
        if(e1==15) e1 = 1;
        else e1++;
        if(s1==28) s1=1;
        else s1++;
        if(m1==19) m1=1;
        else m1++;

        count++;

    }
    cout<<count<<endl;

    return 0;
}