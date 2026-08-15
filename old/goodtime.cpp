#include<bits/stdc++.h>
using ll = long long;
using namespace std;

bool check(ll n)
{
    string s = to_string(n);
    set<char> st(s.begin(), s.end());
    return st.size() <= 2;
}

const int L = 10;
bool dfs(string s,int d,ll x)
{
    if(!s.empty())
    {
        ll y = stoll(s);
        if (y >= 2 &&y <= 1000000000 &&check(x * y))
        {
            cout << y << endl;
            return 1;
        }

        if (s.size() == L)
            return 0;
    }

    for (int i = 0; i <= 9;i++)
    {
        char c = '0' + i;
        if (s.empty() && i == 0)
        continue;

        int new_d = d;
        if(s.find(c)==string::npos)
            new_d++;

        if (new_d <= 2)
        {
            if(dfs(s + c, new_d, x)) 
            return 1;
        }
    }
    return 0;
}

void moink()
{
    ll x;
    cin >> x;
    dfs("", 0, x);
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        moink();
    }
    return 0;
}