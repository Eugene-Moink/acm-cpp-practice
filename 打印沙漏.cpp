#include<iostream>
using namespace std;

int main()
{
    int n;
    char c;
    cin >> n >> c;

    int max_width = 1;

    for (int w = 1;; w += 2)
    {
        int layers = (w + 1) / 2;
        int upper_half_count = (w + 1) * layers / 2;
        int lower_half_count = upper_half_count - w;
        int total_needed = upper_half_count + lower_half_count;

        if (total_needed <= n) 
        {
            max_width = w;
        } 
        else 
        {
            break;
        }
    }

    // --- 修正后的打印上半部分 ---
    for (int width = max_width; width >= 1; width -= 2) { // 将外层循环的变量名改为 width
        int spaces = (max_width - width) / 2;
        // 打印空格
        for (int j = 0; j < spaces; j++) { // 将内层循环的变量名改为 j，避免冲突
            cout << " ";
        }
        // 打印符号
        for (int k = 0; k < width; k++) { // 将内层循环的变量名改为 k，避免冲突
            cout << c;
        }
        // 换行
        cout << endl;
    }

    // --- 修正后的打印下半部分 ---
    for (int width = 3; width <= max_width; width += 2) 
    {
        int spaces = (max_width - width) / 2;
        // 打印空格
        for (int j = 0; j < spaces; j++) 
        {
            cout << " ";
        }
        // 打印符号
        for (int k = 0; k < width; k++) // 将内层循环的变量名改为 k
        {
            cout << c;
        }
        // 换行
        cout << endl;
    }

    // --- 第四步：计算并输出剩余符号 ---
    // 我们需要重新计算一下，总共用了多少个符号
    int layers_used = (max_width + 1) / 2;
    int used_up = (max_width + 1) * layers_used / 2;
    int used_down = used_up - max_width;
    int total_used = used_up + used_down;
    
    int remaining = n - total_used;
    cout << remaining << endl;

    return 0; // main函数应该有返回值
}