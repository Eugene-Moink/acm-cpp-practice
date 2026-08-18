#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    for (int i = 0; i < a.size(); ++i)
    {
        for (char &c : a[i])
        {
            c = tolower(c);
        }
    }

    map<string, int> cnt;
    for (auto s : a)
    {
        cnt[s]++;
    }

    int result = 0;
    for (auto x : cnt)
    {
        result = max(result, x.second);
    }
    cout << result << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}