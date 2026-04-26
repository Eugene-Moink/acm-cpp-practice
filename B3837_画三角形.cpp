#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= i;j++)
        {
            char a = 'A' + (cnt % 26);
            cout << a;
            cnt++;
        }
        cout << endl;
    }
    return 0;
}