#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int main()
{
    int t;  // 测试用例数量
    cin >> t;
    
    while(t--)  // 用t作为循环变量
    {
        int n;  // 每个测试用例的n值
        cin >> n;
        
        long long max_sum = 0;
        int best_x = 2;

        for (int x = 2; x <= n; x++)
        {
            int k = n / x;
            long long sum = (long long)x * k * (k + 1) / 2;

            if(sum > max_sum) 
            {
                max_sum = sum;
                best_x = x;
            }
        }
        cout << best_x << endl;
    }
    return 0;
}