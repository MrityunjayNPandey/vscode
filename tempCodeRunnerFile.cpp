void solve()
{
    int n = 0, potans = 0, ans = 0;
    cin >> n;
    vector<vector<int>> vv;
    for (int i = 0; i < n; i++)
    {
        vector<int> v;
        for (int j = 0; j < 5; j++)
        {
            int temp;
            cin >> temp;
            v.pb(temp);
        }
        vv.pb(v);
    }
    // debug(vv);
    int p = 0, temp = -1;
    while (temp != 1 && temp != 0)
    {
        vector<int> vt;
        if (p == 0)
        {
            for (int i = 1; i < n; i++)
            {
                int t = 0;
                for (int j = 0; j < 5; j++)
                {
                    if (vv[i][j] > vv[0][j])
                    {
                        t++;
                    }
                    if (t == 3)
                    {
                        vt.pb(i);
                        temp++;
                        break;
                    }
                }
            }
            p++;
            debug(vt);
            if (temp == -1)
            {
                potans = 1;
                break;
            }
            if (temp == 0)
            {
                potans = vt[0];
                break;
            }
        }
        temp = 0;
        p = vt[0];
        for (int i = vt[1]; i < vt.size(); i++)
        {
            int t = 0;
            for (int j = 0; j < 5; j++)
            {
                if (vv[i][j] > vv[0][j])
                {
                    t++;
                }
                if (t == 3)
                {
                    vt.pb(i);
                    temp++;
                    break;
                }
            }
        }
        debug(vt);
        if (temp == 0)
        {
            potans = vt[0];
            break;
        }
    }