#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define LOG(n) 31 - __builtin_clz(n)
#define nl "\n"
#define ok cout << "OK\n"
#define ios                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define free                          \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)
#define ff first
#define ss second
typedef pair<int, int> pii;
const long long INF = 1ll << 32;
const long long MAX_N = 1e6 + 7;
const long long MOD = 998244353;
const long long mod = 998244353;
 
int I;
 
void solve()
{
    int n;
    cin>>n;
    int a[n], sum=0, sum_pair=0, ans=0;
    map<int, int> mp;
    for(int i=0; i<n;i++)
        {
            cin>>a[i];
            sum+=a[i];
            mp[a[i]]++;
        }
    //Sum/n=(Sum-(sum_pair))/(n-2)   ->     Sum-(sum_pair)=sum*(n-2)/n
    // -> (sum_pair)= 2*sum/n
    sum_pair=2*sum/n;
    //check if sum_pair is a floating value using ceiling value as 2*sum/n!=(2*sum+n-1)/n
    if(2*sum/n!=(2*sum+n-1)/n)
        {
            //float(not integer)
            cout<<0;
        }
    else 
        {
           for(int i=0;i<n;i++)
            {
                mp[a[i]]--;
                ans+=mp[sum_pair-a[i]];
            }
            cout<<ans;
        }
}

int32_t main()
{
    ios;
    free;
    int Test = 1;
    cin >> Test;
    for (I = 1; I <= Test; I++)
    {
        solve();
        cout << endl;
    }
}