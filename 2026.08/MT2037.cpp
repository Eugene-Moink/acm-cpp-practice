#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll calc(vector<int> &v)
{
    sort(v.begin(), v.end());
    ll res = 0;
    ll prefix = 0;
    for (int i = 0; i < (int)v.size(); i++)
    {
        res += 1LL * v[i] * i - prefix;
        prefix += v[i];
    }
    return res;
}

void moink()
{
    int n, m;
    cin >> n >> m;
    map<int, vector<pair<int, int>>> mp;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int val;
            cin >> val;
            mp[val].push_back({i, j});
        }
    }

    long long ans = 0;
    for (auto &kv : mp)
    {
        vector<int> xs, ys;
        for (auto &p : kv.second)
        {
            xs.push_back(p.first);
            ys.push_back(p.second);
        }
        ans += calc(xs) + calc(ys);
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}

/*
 * ,---.    ,---.    ,-----.   .-./`) ,---.   .--..--.   .--.
 * |    \  /    |  .'  .-,  '. \ .-.')|    \  |  ||  | _/  /
 * |  ,  \/  ,  | / ,-.|  \ _ \/ `-' \|  ,  \ |  || (`' ) /
 * |  |\_   /|  |;  \  '_ /  | :`-'`"`|  |\_ \|  ||(_ ()_)
 * |  _( )_/ |  ||  _`,/ \ _/  |.---. |  _( )_\  || (_,_)   __
 * | (_ o _) |  |: (  '\_/ \   ;|   | | (_ o _)  ||  |\ \  |  |
 * |  (_,_)  |  | \ `"/  \  ) / |   | |  (_,_)\  ||  | \ `'   /
 * |  |      |  |  '. \_/``".'  |   | |  |    |  ||  |  \    /
 * '--'      '--'    '-----'    '---' '--'    '--'`--'   `'-'
 */