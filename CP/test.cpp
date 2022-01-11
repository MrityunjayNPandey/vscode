#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, t = 0, ans = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        t = 0;
        if (a[i] == 2 )
        {
            ans++;
        }
        else
        {
            for (int j = 2; j < a[i]; j++)
            {
                if (a[i] % j == 0)
                {
                    t++;
                    break;
                }
            }
            if (t == 0)
            {
                ans++;
            }
        }
    }
    if (ans == 0)
        cout << -1;
    else
        cout << ans;
}