#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n;
    cin >> n;
    map<string, vector<ll>> mp;
    for (ll player = 0; player < 3;player++)
    {
        for (ll i = 0; i < n;i++)
        {
            string word;
            cin >> word;
            mp[word].push_back(player);
        }
    }

    vector<ll> score(3, 0);
    for (auto &p : mp)
    {
        if (p.second.size() == 1)
        {
            score[p.second[0]] += 3;
        }

        else if(p.second.size() == 2)
        {
            score[p.second[0]] += 1;
            score[p.second[1]] += 1;
        }
    }

    cout << score[0] << " " << score[1] << " " << score[2] << endl;
}

int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        moink();
    }
    return 0;
}