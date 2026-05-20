#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> p(m);
    for (int i = 0; i < n;i++)
    {
        cin >> p[i];
    }

    sort(p.begin(), p.end());

    int best_result = -1;
    int best_price = INT_MAX;

    for (int i = 0; i <= m - 1;i++)
    {
        int price = p[i];
        int buyers = m - i;
        int sold = min(n, buyers);
        int result = price * sold;

        if(result>best_result)
        {
            best_result = result;
            best_price = price;
        }

        else if(result==best_result&&price<best_price)
        {
            best_price = price;
        }
    }

    cout << best_price << " " << best_result;
    return 0;
}