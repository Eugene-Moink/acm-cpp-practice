#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int gcd(int a,int b)
{
    return b ? gcd(b, a % b) : a;
}

vector<int> coprime[1005];
void init()
{
    for (int i = 1; i <= 1000; i++)
    {
        for (int j = 1; j <= 1000;j++)
        {
            if (gcd(i, j) == 1)
            {
                coprime[i].push_back(j);
            }
        }
    }
}

void moink()
{
    int n;
    cin >> n;
    vector<int> last_pos(1005, 0);

    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        last_pos[x] = i;
    }

    int ans = -1;
    for (int i = 1; i <= 1000;i++)
    {
        if (last_pos[i] == 0)
        continue;

        for(int k : coprime[i])
        {
            if(last_pos[k] != 0)
            {
                ans = max(ans, last_pos[i] + last_pos[k]);
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int t;
    cin >> t;
    while(t--)
    {
        moink();
    }
    return 0;
}