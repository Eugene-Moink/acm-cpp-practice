#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int n;
    int cnt=0;
    cin>>n;
    while (n != 0)
    {
        if (n % 2 == 0)
        {
            cnt++;
            n /= 2;
        }
        else
        {
            cnt++;
            n--;
        }
    }
    cout << cnt << endl;
}

int main()
{
    moink();
    return 0;
}