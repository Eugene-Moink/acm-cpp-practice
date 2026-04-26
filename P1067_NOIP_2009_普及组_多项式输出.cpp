#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int cnt = n;
    int first_number;
    cin >> first_number;

    if (first_number != 0)
    {
        if (abs(first_number) != 1 || cnt == 0)
        {
            cout << first_number;
        }
        else
        {
            if (first_number == -1)
            {
                cout << "-";
            }
        }
        if (cnt > 0)
        {
            cout << "x";
            if (cnt > 1)
            {
                cout << "^" << cnt;
            }
        }
    }
    cnt--;

    for (int i = 1; i < n + 1; i++)
    {
        int number;
        cin >> number;
        if (number == 0)
        {
            continue;
        }

        if (number > 0)
        {
            cout << "+";
        }
        else
        {
            cout << "-";
        }

        int abs_number = abs(number);
        if (!(abs_number == 1 && cnt != 0))
        {
            cout << abs_number;
        }

        if (cnt > 0)
        {
            cout << "x";
            if (cnt > 1)
            {
                cout << "^" << cnt;
            }
        }
        cnt--;
    }

    cout << endl;
    return 0;
}
