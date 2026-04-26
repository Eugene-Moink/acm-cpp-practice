#include <iostream>
#include <climits> // 为了防止 i*i*i 溢出，我们用 long long 或检查边界
using namespace std;

int main()
{
    int n;
    cin >> n;

    bool found = false;
    // 循环 i 从 1 开始，直到 i*i*i 大于 n
    // 为了防止 i*i*i 溢出，我们用 long long 来存储立方值
    for (long long i = 1; i * i * i <= n; ++i) 
    {
        if (i * i * i == n) 
        {
            found = true;
            break; // 找到了就可以退出循环了
        }
    }

    if (found) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    
    return 0;
}