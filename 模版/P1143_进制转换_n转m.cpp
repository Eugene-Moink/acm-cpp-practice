#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int val(char c)
{
    if ('0' <= c &&c <= '9')
    {
        return c - '0';
    }

    if ('A' <= c &&c <= 'Z')
    {
        return c - 'A' + 10;
    }

    if ('a' <= c &&c <= 'z')
    {
        return c - 'a' + 10;
    }

    return -1;
}

char dig(int d)
{
    if(d<10)
    {
        return '0' + d;
    }
    return 'A' + (d - 10);
}

int main()
{
    ll n;
    string num;
    cin >> n >> num;
    ll temp = 0;
    for (int i = 0; i < num.size();i++)
    {
        int d = val(num[i]);
        temp = temp * n + d;
    }

    ll m;
    cin >> m;

    string out;
    while(temp>0)
    {
        out.push_back(dig(temp % m));
        temp /= m;
    }
    reverse(out.begin(), out.end());
    cout << out << endl;
    return 0;
}