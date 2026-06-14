#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t;
    cin >> t;
    while(t--)
    {
        ll b, a;  // 注意：这里是b,a顺序，和Python一样
        cin >> b >> a;
        
        ll sol = -1;
        
        // 条件1：如果a+b是偶数
        if ((a + b) % 2 == 0) {
            sol = a + b;
        }
        
        // 条件2：如果a和b都是奇数
        if (a % 2 == 1 && b % 2 == 1) {
            sol = max(sol, a * b + 1);
        }
        // 条件3：如果a是偶数且(a能被4整除或b是偶数)
        else if (a % 2 == 0 && (a % 4 == 0 || b % 2 == 0)) {
            sol = max(sol, 2 + (a * b) / 2);
        }
        
        cout << sol << endl;
    }
    return 0;
}