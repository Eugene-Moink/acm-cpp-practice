#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        long long n, x;
        cin >> n >> x;
        
        // 当x为奇数：只能是a[1]或a[2]，取a[1]时结果最小
        if(x % 2 == 1) {
            cout << x * (1LL << (n-2)) << endl;
            continue;
        }
        
        // 当x为偶数：不断除2直到得到奇数
        long long first_num = x;
        long long count = 2;  // 已经包含了x和前面的数
        
        while(first_num % 2 == 0 && count < n) {
            first_num /= 2;
            count++;
        }
        
        cout << first_num * (1LL << (n-2)) << endl;
    }
    return 0;
}