#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int a;
        cin >> a;
        vector<int> arr(a);

        ll o = 0;
        ll y = 0;
        ll f = 0;
        for (int i = 0; i < a;i++)
        {
            cin >> arr[i];
            if(arr[i]==0)
                o++;
            else if(arr[i]==1)
                y++;
            else
                f++;
        }

        ll ans = 0;
        if(f%2==0)
        {
            ans += o;
        }

        else if(f%2!=0)
        {
            ans += (2 + o);
        }

        else
        {
            ans = o;
        }
        cout << ans << endl;
    }
    return 0;
}