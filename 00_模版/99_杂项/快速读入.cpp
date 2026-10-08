/*
 * 快速读入（getchar 版）
 *
 * 【用途】
 *   输入量极大（约 1e6 个数以上）时替换 cin / scanf，避免读入成为瓶颈；
 *   同时给出关闭流同步的 fast_io()。
 *
 * 【输入】
 *   从标准输入读取；readInt 读一个 int，readLL 读一个 ll，均自动跳过空白、支持负号。
 *
 * 【输出】
 *   readInt()：int；readLL()：ll；读到文件结尾（EOF）时返回 0。
 *   fast_io()：无返回值，启用 ios::sync_with_stdio(false) 与 cin.tie(nullptr)。
 *
 * 【复杂度】
 *   单次读入 O(数字位数)，每个字符只被处理常数次，比 cin 默认同步快数倍。
 *
 * 【易错提醒】
 *   1. 快读只在输入量极大时才有意义：几万个数以内用 cin 加 fast_io() 就足够，
 *      不要为了「看起来快」到处混用多种读入方式。
 *   2. 不要与 scanf 混用（缓冲各自独立，会读到错误位置）；与 cin 混用时必须先 fast_io()，
 *      且不要在中间穿插 scanf / getchar 读同一段输入。
 *   3. getchar 声明在 <cstdio> 中，本文件依赖外层已 #include <bits/stdc++.h>。
 *   4. 文件结尾 getchar() 返回 EOF：内层 while 条件写成 (c >= '0' && c <= '9') 就天然安全，
 *      读到 EOF 会立即退出；外层 while 也需要 while (c <= ' ' && c != EOF) 才是 EOF 安全的。
 *      注意本实现读到 EOF 时返回 0，与合法的输入 0 无法区分，多组数据请自行读入组数 T。
 *   5. getchar 读单个字符与 cin >> ch 混用会吞掉或留下换行，字符题一律统一用一种读入方式。
 */

const ll INF = 1e18;
const int MOD = 998244353;

/* ==================== ① 整数快读 ==================== */

int readInt()
{
    int c = getchar();
    while (c <= ' ' && c != EOF)
        c = getchar();

    int sign = 1;
    if (c == '-')
    {
        sign = -1;
        c = getchar();
    }

    int x = 0;
    while (c >= '0' && c <= '9')
    {
        x = x * 10 + (c - '0');
        c = getchar();
    }

    return sign * x;
}

ll readLL()
{
    int c = getchar();
    while (c <= ' ' && c != EOF)
        c = getchar();

    ll sign = 1;
    if (c == '-')
    {
        sign = -1;
        c = getchar();
    }

    ll x = 0;
    while (c >= '0' && c <= '9')
    {
        x = x * 10 + (c - '0');
        c = getchar();
    }

    return sign * x;
}

void fast_io()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

/* ==================== ② 注意事项 ====================
   1. 快读与 scanf 不能混用；与 cin 混用前必须先调用 fast_io()。
   2. getchar 需要 <cstdio>（bits/stdc++.h 已包含）。
   3. EOF 处理：内层 while 靠 c >= '0' && c <= '9' 自动停下，
      外层 while 靠 c != EOF 退出，越界读不会发生；返回 0 表示本次没有读到数字。
   4. 只想读整数用 readInt / readLL；要读字符串或单个字符时，用 getchar 自己跳过空白，
      不要在这一段里穿插 cin >> s。
==================================================================== */

/* ==================== 调用示例（贴进自己的 main） ====================
    fast_io();

    int T = readInt();
    while (T--)
    {
        int n = readInt();
        ll sum = 0;
        for (int i = 0; i < n; i++)
            sum += readLL();
        cout << sum << "\n";
    }

    ll x = readLL();
    cout << x << "\n";
==================================================================== */
