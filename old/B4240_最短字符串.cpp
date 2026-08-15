#include<bits/stdc++.h> 
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;

    vector<ll> total(128, 0);
    ll need=0;

    for (char ch : s)
    {
        if(total[ch]==0)
        {
            need++;
        }
        total[ch]++;
    }

    ll l = 0;
    vector<ll> cnt(128, 0);
    ll have = 0;
    ll ans = n;

    for (int r = 0; r < n; r++)
    {
        char ch = s[r];

        if (cnt[ch] == 0)
        {
            have++;
        }
        cnt[ch]++;
        while (have == need)
        {
            ans = min(ans, r - l + 1);

            char leftChar = s[l];
            cnt[leftChar]--;

            if (cnt[leftChar] == 0)
            {
                have--;
            }

            l++;
        }
    }
    cout << ans << endl;
    return 0;
}