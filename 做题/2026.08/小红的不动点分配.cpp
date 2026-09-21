#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n;
    cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n * 2; ++i)
    {
        int x;
        cin >> x;
        if (x <= n)
            cnt[x]++;
    }

    ll ans = 0;
    for (auto &p : cnt)
    {
        ans += min(2, p.second);
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