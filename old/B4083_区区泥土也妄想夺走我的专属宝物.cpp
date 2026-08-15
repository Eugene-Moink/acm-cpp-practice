#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int n;
    cin >> n;
    cout << fixed << setprecision(10);
    for (int i = 0; i < n; i++) 
    {
        int a;
        cin >> a;
        int y = 0;
        for (int j = 0; j < a; j++) 
        {
            int x;
            cin >> x;
            if (x == 1) y++;
        }
        double dirt = (double)(a - y) / a;
        cout << dirt << endl;
    }
}

int main()
{
    moink();
    return 0;
}