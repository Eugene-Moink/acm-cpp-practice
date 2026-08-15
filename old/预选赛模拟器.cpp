#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;

    int pass = 0, cnt_b = 0;

    for (char ch : s)
    {
        if (ch == 'a')
        {
            if (pass < a + b)
            {
                cout << "Yes\n";
                pass++;
            }
            else
            {
                cout << "No\n";
            }
        }
        else if (ch == 'b')
        {
            cnt_b++;
            if (pass < a + b && cnt_b <= b)
            {
                cout << "Yes\n";
                pass++;
            }
            else
            {
                cout << "No\n";
            }
        }
        else // 'c'
        {
            cout << "No\n";
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}