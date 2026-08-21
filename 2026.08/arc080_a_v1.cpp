#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
    {
        cin >> x;
    }

    int cnt1 = 0, cnt2 = 0, cnt4 = 0;
    for (int x : a)
    {
        if (x % 4 == 0)
            cnt4++;
        else if (x % 2 == 0 && x % 4 != 0)
            cnt2++;
        else
            cnt1++;
    }

    if (cnt1 == 0)
    {
        cout << "Yes\n";
        return;
    }
    else
    {
        if (cnt2 == 0)
        {
            if (cnt4 >= cnt1 - 1)
            {
                cout << "Yes\n";
            }
            else
                cout << "No\n";

            return;
        }

        if (cnt2 > 0 && cnt4 >= cnt1)
        {
            cout << "Yes\n";
            return;
        }

        else
            cout << "No\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}