#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int n;
    cin >> n;
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n;i++)
    {
        int x;
        cin >> x;
        if(x%3==0)
            cnt0++;
        else if(x%3==1)
            cnt1++;
        else
            cnt2++;
    }
    cout << cnt0 / 2 + min(cnt1, cnt2);
}

int main()
{
    moink();
    return 0;
}