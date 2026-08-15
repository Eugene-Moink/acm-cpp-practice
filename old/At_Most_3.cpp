#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int N, W;
    cin >> N >> W;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    vector<ll> good;
    for (int i = 0; i < N; i++)
    {
        good.push_back(a[i]);
        for (int j = i + 1; j < N; j++)
        {
            good.push_back((ll)a[i] + a[j]);
            for (int k = j + 1; k < N; k++)
            {
                good.push_back((ll)a[i] + a[j] + a[k]);
            }
        }
    }

    sort(good.begin(), good.end());
    good.erase(unique(good.begin(), good.end()), good.end());

    ll ans = upper_bound(good.begin(), good.end(), (ll)W) - good.begin();
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    moink();
    return 0;
}