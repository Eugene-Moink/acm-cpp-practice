#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    string all = "";
    string line;
    while (getline(cin, line))
    {
        size_t pos = line.find('E');
        if (pos != string::npos)
        {
            all += line.substr(0, pos);
            break;
        }
        else
        {
            all += line;
        }
    }

    auto print = [&](int limit)
    {
        int w = 0, l = 0;
        for (char c : all)
        {
            if (c == 'W')
                w++;
            else if (c == 'L')
                l++;
            if ((w >= limit || l >= limit) && abs(w - l) >= 2)
            {
                cout << w << ':' << l << '\n';
                w = l = 0;
            }
        }
        cout << w << ':' << l << '\n';
    };

    print(11);
    cout << '\n';
    print(21);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}