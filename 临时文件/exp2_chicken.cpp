/*==============================================================================
 * 实验二  蛮力法与改进版"百鸡问题"算法的设计与分析
 *------------------------------------------------------------------------------
 * 编译环境 : g++ (TDM64 MinGW-w64) 10.3.0  -std=c++17 -O2
 * 问题描述 : 公鸡 5 钱 1 只，母鸡 3 钱 1 只，小鸡 1 钱 3 只。
 *            用 n 钱买 n 只鸡，问公鸡 a、母鸡 b、小鸡 c 各多少只？
 * 约束条件 : a >= 0, b >= 0, c >= 0, c % 3 == 0, a + b + c = n, 5a + 3b + c/3 = n
 * 编程要求 : 使用数组存储多组解，禁止使用全局变量
 * 统计指标 : 循环体执行次数、执行时间（chrono，微秒级）
 *============================================================================*/
 
#include <cstdio>
#include <cstdlib>
#include <chrono>
#ifdef _WIN32
#include <windows.h>
#endif
 
using namespace std;
 
const int MAXN = 10000;                 // n 的最大取值
const int MAXSOL = 2000;                // 解的最大组数（n <= 10000 时远小于此值）
 
/*==============================================================================
 * 模块1：输入处理
 *------------------------------------------------------------------------------
 * 读取鸡的总数 n（正整数，1~10000），若输入非法则提示并重新输入。
 * 注意：本实验中"总钱数"与"总鸡数"取值相同，均为同一个参数 n，
 *       即约束 5a + 3b + c/3 = n 与 a + b + c = n 中的 n 是同一个数。
 *============================================================================*/
int readN()
{
    int n;
    while (true)
    {
        printf("请输入鸡的总数 n (1 ~ 10000): ");
        if (scanf("%d", &n) == 1 && n >= 1 && n <= 10000)   // 合法：正整数且在范围内
            return n;
        printf("  [输入非法] n 必须是 1 ~ 10000 之间的正整数，请重新输入。\n");
        int ch; while ((ch = getchar()) != '\n' && ch != EOF) { }   // 清空非法输入
    }
}
 
/*==============================================================================
 * 模块2：基础蛮力法
 *------------------------------------------------------------------------------
 * 思路：最朴素的"枚举所有可能组合 + 验证约束条件"。
 *       外层循环枚举公鸡数 a，内层循环枚举母鸡数 b，
 *       小鸡数由 a + b + c = n 直接推出 c = n - a - b，
 *       再验证 c >= 0、c % 3 == 0、5a + 3b + c/3 == n 是否成立。
 * 枚举范围：a 和 b 都取 [0, n]，各有 n+1 种取值。
 * 循环体执行次数：恰好 (n+1)^2 次，与数据无关，恒为 n^2 + 2n + 1。
 * 时间复杂度：O(n^2)      空间复杂度：O(k)，k 为解的组数
 * 参数：用数组返回所有解及解的总数，并返回循环体执行次数
 *============================================================================*/
long long solveBasicBruteForce(int n, int sa[], int sb[], int sc[], int &count)
{
    long long loops = 0;
    count = 0;
    for (int a = 0; a <= n; ++a)                    // 枚举公鸡数 a
    {
        for (int b = 0; b <= n; ++b)                // 枚举母鸡数 b
        {
            ++loops;                                // 统计一次循环体执行
            int c = n - a - b;                      // 由 a + b + c = n 推出小鸡数
            if (c < 0) continue;                    // 约束：c >= 0
            if (c % 3 != 0) continue;               // 约束：c % 3 == 0，小鸡须 3 只一组
            // 约束：钱数之和等于 n；把 5a+3b+c/3==n 两边乘 3，避免整数除法误差：
            //   5a + 3b + c/3 == n  等价于  15a + 9b + c == 3n
            if (15 * a + 9 * b + c == 3 * n)
            {
                sa[count] = a; sb[count] = b; sc[count] = c;
                ++count;                            // 存入解数组
            }
        }
    }
    return loops;
}
 
/*==============================================================================
 * 模块3：改进蛮力法（利用约束条件把枚举量降到 O(n)）
 *------------------------------------------------------------------------------
 * 推导过程（约束条件化简是本算法的核心）：
 *   由  a + b + c = n              ......(1)
 *       5a + 3b + c/3 = n          ......(2)
 *   把 (1) 式乘以 3 得  3a + 3b + 3c = 3n    ......(3)
 *   把 (2) 式乘以 3 得  15a + 9b + c = 3n    ......(4)
 *   (4) - (3) 消去 n 与 c：12a + 6b - 2c = 0  =>  c = 6a + 3b
 *   代回 (1) 式：a + b + 6a + 3b = n  =>  7a + 4b = n  =>  b = (n - 7a) / 4
 *   于是：只要枚举一个变量 a，b 和 c 都能直接算出，双重循环化为单重循环！
 *
 * 枚举范围优化：由 b = (n - 7a)/4 >= 0 得 a <= n/7，
 *               故 a 只需枚举 [0, n/7]，共 n/7 + 1 次，
 *               循环体执行次数从 (n+1)^2 降到约 n/7 + 1。
 * 时间复杂度：O(n)（相比基础版 O(n^2) 降低了一个数量级）
 *============================================================================*/
long long solveImprovedBruteForce(int n, int sa[], int sb[], int sc[], int &count)
{
    long long loops = 0;
    count = 0;
    for (int a = 0; a <= n / 7; ++a)                // 枚举范围优化：a <= n/7
    {
        ++loops;                                    // 统计一次循环体执行
        int rest = n - 7 * a;                       // rest = 4b
        if (rest % 4 != 0) continue;                // 约束：b = (n-7a)/4 必须是整数
        int b = rest / 4;                           // 直接算出母鸡数
        int c = n - a - b;                          // 由 (1) 式算出小鸡数
        if (b < 0 || c < 0) continue;               // 约束：b >= 0, c >= 0
        if (c % 3 != 0) continue;                   // 约束：c % 3 == 0
        sa[count] = a; sb[count] = b; sc[count] = c;
        ++count;                                    // 存入解数组
    }
    return loops;
}
 
/*==============================================================================
 * 模块4：结果输出与时间统计
 *============================================================================*/
 
/* 计时函数：把某一种算法连续执行 repeat 次，用总耗时除以 repeat 得到单次平均
 * 耗时（微秒）。
 * 为什么要重复多次：改进蛮力法的单次执行只要零点几微秒，直接用时钟测量会被
 * 计时器分辨率淹没（结果恒为 0.000 微秒），重复执行后总耗时足够大，数据才有意义。
 * 参数：basic = true 时测基础蛮力法，false 时测改进蛮力法 */
double measureUs(int n, bool basic, long long repeat)
{
    int sa[MAXSOL], sb[MAXSOL], sc[MAXSOL];
    int count = 0;
    long long loops = 0;
    auto t0 = chrono::high_resolution_clock::now();
    for (long long r = 0; r < repeat; ++r)
    {
        if (basic) loops = solveBasicBruteForce(n, sa, sb, sc, count);
        else       loops = solveImprovedBruteForce(n, sa, sb, sc, count);
    }
    auto t1 = chrono::high_resolution_clock::now();
    (void)loops;
    return chrono::duration<double, micro>(t1 - t0).count() / (double)repeat;
}
 
/* 输出一种算法的求解结果：所有合法解、循环体执行次数、单次执行时间 */
void printResult(const char *title, const int sa[], const int sb[], const int sc[],
                 int count, long long loops, double us)
{
    printf("\n--------------------------------------------------------------\n");
    printf("  %s\n", title);
    printf("--------------------------------------------------------------\n");
    printf("  共求得合法解 %d 组：\n", count);
    const int LIMIT = 12;                            // 解太多时只显示前 12 组
    for (int i = 0; i < count && i < LIMIT; ++i)
        printf("    [%2d] 公鸡：%3d 只，母鸡：%3d 只，小鸡：%3d 只\n",
               i + 1, sa[i], sb[i], sc[i]);
    if (count > LIMIT)
        printf("    ......(其余 %d 组解略)......\n", count - LIMIT);
    printf("  循环体执行次数：%lld 次\n", loops);
    printf("  单次执行时间：%.3f 微秒\n", us);
}
 
int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);            // 输出改为 UTF-8，保证中文不乱码
#endif
    printf("==============================================================\n");
    printf("   实验二  蛮力法与改进版 百鸡问题 算法对比\n");
    printf("   公鸡 5 钱/只, 母鸡 3 钱/只, 小鸡 1 钱/3 只, 用 n 钱买 n 只鸡\n");
    printf("   时间统计: C++11 <chrono> 高精度时钟 (微秒)\n");
    printf("==============================================================\n");
 
    int n = readN();
 
    /* ---------- 求解：基础蛮力法 ---------- */
    int sa1[MAXSOL], sb1[MAXSOL], sc1[MAXSOL];
    int count1 = 0;
    long long loops1 = solveBasicBruteForce(n, sa1, sb1, sc1, count1);
 
    /* ---------- 求解：改进蛮力法 ---------- */
    int sa2[MAXSOL], sb2[MAXSOL], sc2[MAXSOL];
    int count2 = 0;
    long long loops2 = solveImprovedBruteForce(n, sa2, sb2, sc2, count2);
 
    /* ---------- 正式计时：重复执行取平均 ---------- */
    // 重复次数按问题规模选取：两种算法单次耗时都远小于 1 微秒（n 较小时尤其明显），
    // 必须重复足够多次，使总耗时达到毫秒量级，测量结果才稳定可靠。
    // 基础蛮力法耗时为 O(n^2)，故重复次数取 n^2 的反比；改进蛮力法取固定值。
    long long REPEAT_BASIC    = 20000000LL / ((long long)n * n);   // 基础蛮力法重复次数
    if (REPEAT_BASIC < 10) REPEAT_BASIC = 10;
    const long long REPEAT_IMPROVED = 1000000;                     // 改进蛮力法重复次数
    double us1 = measureUs(n, true,  REPEAT_BASIC);
    double us2 = measureUs(n, false, REPEAT_IMPROVED);
 
    printResult("基础蛮力法 求解结果", sa1, sb1, sc1, count1, loops1, us1);
    printResult("改进蛮力法 求解结果", sa2, sb2, sc2, count2, loops2, us2);
    printf("  (基础蛮力法重复执行 %lld 次取平均，改进蛮力法重复执行 %lld 次取平均)\n",
           REPEAT_BASIC, REPEAT_IMPROVED);
 
    /* ---------- 结果一致性校验 ---------- */
    bool same = (count1 == count2);
    if (same)
        for (int i = 0; i < count1; ++i)
            if (sa1[i] != sa2[i] || sb1[i] != sb2[i] || sc1[i] != sc2[i])
            {
                same = false;
                break;
            }
 
    /* ---------- 优化效果对比 ---------- */
    printf("\n==============================================================\n");
    printf("  优化效果对比（n = %d）\n", n);
    printf("==============================================================\n");
    printf("  基础蛮力法循环次数：%10lld 次\n", loops1);
    printf("  改进蛮力法循环次数：%10lld 次\n", loops2);
    printf("  循环次数降低倍数  ：%10.1f 倍\n",
           loops2 > 0 ? (double)loops1 / (double)loops2 : 0.0);
    printf("  基础蛮力法耗时    ：%10.3f 微秒\n", us1);
    printf("  改进蛮力法耗时    ：%10.3f 微秒\n", us2);
    printf("  耗时降低倍数      ：%10.1f 倍\n",
           us2 > 0 ? us1 / us2 : 0.0);
    printf("  两算法解集是否一致：%s\n", same ? "一致 (改进算法正确)" : "不一致");
    printf("==============================================================\n");
    return 0;
}
