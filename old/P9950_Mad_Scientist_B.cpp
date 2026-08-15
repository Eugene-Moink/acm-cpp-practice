#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    int n;
    cin >> n;

    string A;
    cin >> A;

    string B;
    cin >> B;

    int ans = 0;
    for (int i = 0; i < n;i++)
    {
        if (A[i] != B[i] && (i == 0 || A[i-1] == B[i-1]))
        ans++;
    }
    cout << ans << endl;
    return 0;
}