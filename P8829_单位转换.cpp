#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    string s;
    cin >> s;

    size_t pos = s.find("=?");
    string left = s.substr(0, pos);
    string u2 = s.substr(pos + 2);

    ll k = 0;
    while (k < (ll)left.size() && isdigit(left[k])) 
        k++;

    ll x = stoll(left.substr(0, k));
    string u1 = left.substr(k);

    unordered_map<string, int> e;
    e["B"] = 0; e["KB"] = 10; e["MB"] = 20; e["GB"] = 30;

    double ans = x * pow(2.0, e[u1] - e[u2]);
    cout << fixed << setprecision(6) << ans << "\n";
}