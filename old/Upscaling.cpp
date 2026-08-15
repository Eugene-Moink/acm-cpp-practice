#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int n;
    cin >> n;
    int size = 2 * n;
    for (int i = 0; i < size;i++)
    {
        for (int j = 0; j < size;j++)
        {
            if (((i / 2) + (j / 2)) % 2 == 0)
                cout << '#';
            else
                cout << '.';
        }
        cout << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        moink();
    }
    return 0;
}