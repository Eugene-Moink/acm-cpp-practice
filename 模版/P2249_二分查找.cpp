/*
 * ==========================================
 * 二分查找通用模板（solve 结构）
 * ==========================================
 *
 * 【适用场景】
 * 在一个有序数组中，查找某个 target 第一次出现的位置（0-based 下标）。
 * 如果不存在，返回 -1。
 *
 * 【核心函数】
 * find_first_position(const vector<ll>& arr, ll target)
 * - arr: 有序数组（必须已升序排序）
 * - target: 要查找的值
 * - 返回值: 目标值的下标（从 0 开始）。找不到返回 -1。
 *
 * 【solve() 内部逻辑】
 * 1. 读取 n（数组长度）和 m（查询次数）
 * 2. 读取 n 个数组元素并排序
 * 3. 循环 m 次，每次读取一个查询值，调用二分函数并输出结果（输出 1-based 下标，找不到输出 -1）
 *
 * 【如何适配多组测试数据】
 * 默认只跑 1 组数据。如果题目是多组数据（例如第一行给定 T），
 * 把 main() 函数中 // cin >> T; 前面的注释去掉即可。
 *
 * 【重要提醒】
 * 此模板的输出格式为“每个查询结果独占一行”。
 * 如果题目要求行末输出空格（例如：1 2 3 ），请修改 solve() 里的输出语句。
 *
 * ==========================================
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll find_first_position(const vector<ll> &arr, ll target)
{
    ll left = 0, right = arr.size();

    while (left < right)
    {
        ll mid = left + (right - left) / 2;
        if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }

    if (left < arr.size() && arr[left] == target)
    {
        return left;
    }
    return -1;
}

void solve()
{
    ll n, m;
    if (!(cin >> n >> m))
        return;

    vector<ll> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < m; ++i)
    {
        ll num;
        cin >> num;

        ll pos = find_first_position(arr, num);
        if (pos != -1)
        {
            cout << pos + 1 << "\n";
        }
        else
        {
            cout << "-1\n";
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}