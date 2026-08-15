#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int n;
    string s;
    cin >> n >> s;

    unordered_map<string, int> cnt;
    int max_cnt = 0;
    string ans = "";

    for (int i = 0; i < n - 1;i++)
    {
        string sub = s.substr(i, 2);
        cnt[sub]++;

        if (cnt[sub] > max_cnt)
        {
            max_cnt = cnt[sub];
            ans = sub;
        }
        else if(cnt[sub]==max_cnt)
        {
            if (ans == "" || sub < ans)
            {
                ans = sub;
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    moink();
    return 0;
}