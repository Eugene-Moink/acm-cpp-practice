#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int assignMap[26];
bool usedDigit[10];
vector<char> chars;
string s;
bool found = false;

bool isPrime(ll x)
{
    if (x < 2)
        return false;
    for (ll i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

void dfs(int idx)
{
    if (found)
        return;
    if (idx == (int)chars.size())
    {
        string numStr;
        for (char c : s)
        {
            numStr += char('0' + assignMap[c - 'a']);
        }
        if (numStr[0] == '0')
            return;
        ll p = stoll(numStr);
        if (isPrime(p))
        {
            cout << p << '\n';
            found = true;
        }
        return;
    }

    for (int d = 0; d <= 9; d++)
    {
        if (usedDigit[d])
            continue;
        usedDigit[d] = true;
        assignMap[chars[idx] - 'a'] = d;
        dfs(idx + 1);
        usedDigit[d] = false;
        if (found)
            return;
    }
}

void solve()
{
    cin >> s;

    bool seen[26] = {false};
    for (char c : s)
    {
        if (!seen[c - 'a'])
        {
            seen[c - 'a'] = true;
            chars.push_back(c);
        }
    }

    if ((int)chars.size() > 10)
    {
        cout << -1 << '\n';
        return;
    }

    dfs(0);

    if (!found)
        cout << -1 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}