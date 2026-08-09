#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    string s;
    cin >> s;
    stack<char> st;
    int ans = 0;
    for (char c : s)
    {
        if(!st.empty() && st.top() == c)
            st.pop(),ans++;

        else
            st.push(c);
    }
    cout << (ans % 2 ? "Yes" : "No") << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}  