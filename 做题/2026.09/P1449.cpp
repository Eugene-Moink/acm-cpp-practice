#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    string s;
    cin >> s;

    stack<ll> st;
    string num = "";
    for (char c : s)
    {
        if (c == '@')
            break;
        if (c == '.')
        {
            if (!num.empty())
            {
                st.push(stoi(num));
                num.clear();
            }
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();

            int res = 0;
            if (c == '+')
                res = a + b;
            else if (c == '-')
                res = a - b;
            else if (c == '*')
                res = a * b;
            else if (c == '/')
                res = a / b;

            st.push(res);
        }
        else
        {
            num += c;
        }
    }
    cout << st.top() << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}