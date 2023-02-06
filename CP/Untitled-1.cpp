#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n_cus, w_time, break_size, i;
    cin >> n_cus >> w_time >> break_size;

    vector<pair<int, int>> v(n_cus);

    for (i = 0; i < n_cus; i++)
    {
        cin >> v[i].first;
        cin >> v[i].second;
    }

    if (n_cus == 0)
    {
        int out;
        out = w_time / break_size;
        cout << out;
    }
    else
    {
        int count, v_temp, temp;
        count = v[0].first / break_size;

        for (i = 0; i < n_cus; i++)
        {
            if (i == n_cus - 1)
            {
                v_temp = v[i].first + v[i].second;
                temp = (w_time - v_temp) / break_size;
                count += temp;
                break;
            }
            else
            {
                v_temp = v[i].first + v[i].second;
                count += (v[i + 1].first - v_temp) / break_size;

            }
        }

        cout << count;
    }
    return 0;
}