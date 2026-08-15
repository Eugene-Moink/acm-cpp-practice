#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int n;
    cin >> n;

    int max_score = -1, ans_index = -1;
    unordered_set<string> seen;
    for (int i = 0; i < n;i++)
    {
        string cur_s;
        int cur_t;
        cin >> cur_s >> cur_t;

        if (seen.count(cur_s) == 0)
        {
            seen.insert(cur_s);
            if (cur_t > max_score)
            {
                max_score = cur_t;
                ans_index = i + 1;
            }
        }
    }
    cout << ans_index << endl;
}

int main()
{
    moink();
    return 0;
}