#include<bits/stdc++.h>
using namespace std;
int main(){
    queue<int> q;
    for(int i=0;i<20;i++){
        q.push(i);
    }
    while(!q.empty()){
        cout<<q.front()<<"\n";
        q.pop();
        // it++;
    }
    return 0;
}