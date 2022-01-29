

    // #include <bits/stdc++.h>
    // int main(){
    // 	int n,k,t,e,o;
    // 	std::cin>>t;
    // 	while(t--){
    // 		std::string s;
    // 		std::cin>>n>>k>>s;
    // 		int c[200]={0};
    // 		for(auto i:s)c[i]++;
    // 		e=0,o=0;
    // 		for(int i=0;i<199;i++)e+=c[i]/2,o+=c[i]%2;
    // 		n=e/k*2;
    // 		std::cout<<(!n?1:(n+(e%k*2+o>=k)))<<'\n';
    // 	}
    // }

        #include<bits/stdc++.h>
    using namespace std;
    int main()
    {
    	int t;
    	cin>>t;
    	while(t--){
    		int n,k;
    		cin>>n>>k;
    		string str;
    		cin>>str;
    		map<char,int> c;
    		for(char x:str)c[x]++;
    		int tt=0;
    		for(auto x:c)tt+=x.second/2;
    		int result=tt/k;
    		result*=2;
    		if(n>=k+result*k)result++;
    		cout<<result<<endl;
    	}
    	return 0;
    }
