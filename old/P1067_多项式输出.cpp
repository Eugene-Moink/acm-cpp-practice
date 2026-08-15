#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int n;
    cin >> n;
    int a[105];

    for (int i = 0; i <= n; i++) 
    {
        int c;
        cin >> c;
        a[n - i] = c;
    }

    bool first = true;
    for (int i = n; i >= 0; i--) 
    {
        int coef = a[i];
        if (coef == 0) continue;
        if (first) 
        {
            first = false;
            if (coef < 0) cout << '-';
            int absCoef = abs(coef);
            if (absCoef != 1 || i == 0) cout << absCoef;
            if (i > 1) cout << "x^" << i;
            else if (i == 1) cout << "x";
        } 
        else {
            cout << (coef > 0 ? '+' : '-');
            int absCoef = abs(coef);
            if (absCoef != 1 || i == 0) cout << absCoef;
            if (i > 1) cout << "x^" << i;
            else if (i == 1) cout << "x";
        }
    }
    cout << endl;
}

int main()
{
    moink();
    return 0;
}