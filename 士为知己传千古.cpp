#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

void moink()
{
    string s;
    cin >> s;
    vector<int> cnt(256, 0);
    for(char c : s) 
    {
        cnt[c]++;
    }

    int cnt_MATIJI = min({cnt['M'], cnt['A'], cnt['T'], cnt['J'], cnt['I'] / 2});

    int cnt_matiji = min({cnt['m'], cnt['a'], cnt['t'], cnt['j'], cnt['i'] / 2});

    cout << cnt_MATIJI << " " << cnt_matiji << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    moink();
    return 0;
}