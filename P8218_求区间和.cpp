#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> number(n+1);
    for (int i = 1; i <= n;i++){
        cin >> number[i];
    }

    vector<long long> prefix(n+1);
    prefix[0] = number[0];
    for (int i = 1; i <= n;i++){
        prefix[i] = prefix[i - 1] + number[i];
    }

    int T;
    cin >> T;
    while (T--)
    {
        int l, r;
        cin >> l >> r;
        cout << prefix[r] - prefix[l - 1] << endl;
    }
    return 0;
}