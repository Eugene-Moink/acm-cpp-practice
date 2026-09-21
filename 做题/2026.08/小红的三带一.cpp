#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    int ans = 0;
    for (int i = 0; i + 3 < n;)
    {
        vector<int> v = {a[i], a[i + 1], a[i + 2], a[i + 3]};
        sort(v.begin(), v.end());

        if ((v[0] == v[1] && v[1] == v[2] && v[2] != v[3]) ||
            (v[1] == v[2] && v[2] == v[3] && v[0] != v[1]))
        {
            ans++;
            i += 4;
        }
        else
        {
            i++;
        }
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