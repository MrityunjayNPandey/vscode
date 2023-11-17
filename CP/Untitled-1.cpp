#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string str;
    cin>>str;
    int ans = 0;
    for(int i = 0; i<n; i++){
        int k = 0;
        int sumL = 0, sumR = 0;
        while(i - k >=0 && i + 1 + k <= n - 1){
            sumL += str[i - k] - '0';
            sumR += str[i + 1 + k] - '0';
            if(sumL == sumR){
                ans = max(ans, 2*(k + 1));
            }
            k++;
        } 
    }
    cout<<ans;
}