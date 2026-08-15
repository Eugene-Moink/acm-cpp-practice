#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    string s;
    cin >> s;
    ll arr[26]={0};
    for (ll i = 0; i < s.size();i++)
    {
        arr[s[i] - 'a']++;
    }

    ll max_cnt = 0;
    ll best_idx = 0;
    for (ll i = 0; i < 26; i++)
    {
        if (arr[i] > max_cnt)
        {
            max_cnt = arr[i];
            best_idx = i;
        }
    }

    char result = 'a' + best_idx;
    cout << result << endl;
}

int main()
{
    moink();
    return 0;
}