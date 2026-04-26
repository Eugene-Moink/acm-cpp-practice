#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, m, s;
    cin >> h >> m >> s; // 读取起始时间
    
    int k;
    cin >> k; // 读取学习秒数

    // 1. 将起始时间转换为从 00:00:00 开始的总秒数
    long long start_seconds = (long long)h * 3600 + m * 60 + s;

    // 2. 加上学了 k 秒
    long long end_total_seconds = start_seconds + k;

    // 3. 将总秒数转换回时、分、秒
    int final_hour = end_total_seconds / 3600;
    
    int remaining_after_hour = end_total_seconds % 3600; // 计算剩余的秒数（不够一小时）
    int final_minute = remaining_after_hour / 60;
    int final_second = remaining_after_hour % 60;

    // 4. 输出结果
    cout << final_hour << " " << final_minute << " " << final_second << endl;

    return 0;
}