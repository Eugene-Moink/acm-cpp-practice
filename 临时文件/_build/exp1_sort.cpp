/*==============================================================================
 * 实验一  冒泡排序、选择排序、归并排序的设计与性能分析
 *------------------------------------------------------------------------------
 * 编译环境 : g++ (TDM64 MinGW-w64) 10.3.0  -std=c++17 -O2
 * 编程要求 : 使用 C/C++ 实现，禁止使用标准库（std::sort / qsort）中的排序函数
 * 统计指标 : 比较次数、元素移动次数、执行时间（chrono，微秒级）
 *------------------------------------------------------------------------------
 * 关于"移动次数"的口径说明（本实验采用的口径）：
 *   每一次对数组位置的写操作记 1 次移动，即
 *     · 赋值        a[i] = x;           记 1 次
 *     · 一次交换    temp=a[i]; a[i]=a[j]; a[j]=temp;   记 3 次
 *   归并排序中，把辅助数组元素写回原数组的复制操作同样计入移动次数。
 *   三种算法采用同一口径，因此比较结果具有可比性。
 *============================================================================*/
 
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <chrono>
#ifdef _WIN32
#include <windows.h>
#endif
 
using namespace std;
 
const int MAXN = 10000;          // 最大数据规模
int  buf[MAXN];                  // 归并排序使用的辅助数组（模块4使用）
 
/* 三个排序函数的声明，供后面的计时函数调用 */
void bubbleSort(int a[], int n, long long &cmp, long long &moves);
void selectionSort(int a[], int n, long long &cmp, long long &moves);
void mergeSort(int a[], int n, long long &cmp, long long &moves);
 
/*==============================================================================
 * 模块1：随机数组生成
 *------------------------------------------------------------------------------
 * 说明：使用 C 语言标准随机数函数 srand() / rand() 生成 [1, 100000] 的随机整数。
 *       rand() 返回 0 ~ RAND_MAX 的伪随机整数，用
 *           rand() % 100000 + 1
 *       即可映射到区间 [1, 100000] 上。
 *       srand(seed) 设置随机数种子，实验中用固定种子，保证每次运行生成的随机
 *       数组完全相同，实验结果可复现；同一规模下三种算法共用同一份数组，
 *       因此比较是公平的。
 *       注意：rand() 的取值只有 32768 个（RAND_MAX = 32767），映射到 100000 个
 *       取值上必然出现重复元素，即生成的随机整数允许重复，符合实验要求。
 *============================================================================*/
void genRandomArray(int a[], int n, unsigned seed)
{
    srand(seed);                                 // 设置随机数种子
    for (int i = 0; i < n; ++i)
        a[i] = rand() % 100000 + 1;              // 映射到 [1, 100000]
}
 
/*==============================================================================
 * 模块5：输出与性能测试（基础部分）
 *============================================================================*/
 
/* 按算法编号调用对应的排序函数：which = 0 冒泡, 1 选择, 2 归并 */
void callSort(int which, int a[], int n, long long &cmp, long long &moves)
{
    if (which == 0)      bubbleSort(a, n, cmp, moves);
    else if (which == 1) selectionSort(a, n, cmp, moves);
    else                 mergeSort(a, n, cmp, moves);
}
 
/*------------------------------------------------------------------------------
 * 计时函数：对同一个随机数组反复排序 repeat 次，用总耗时除以 repeat 得到
 * 单次平均耗时（微秒）。
 * 为什么要重复多次：在编译优化下，小规模数据的排序单次耗时常常不足 1 微秒，
 * 直接测量会被时钟分辨率淹没，出现大量 0.000 微秒或大幅跳变的无效数据。
 * 重复执行后总耗时足够大，测量结果才稳定、可复现。
 * 每次排序前都重新拷贝一份原始数组，保证每次都是对无序数组排序。
 *------------------------------------------------------------------------------*/
double measureUs(int which, const int src[], int n, long long repeat)
{
    int work[MAXN];
    long long cmp = 0, moves = 0;                // 计时期间不关心统计量
    auto t0 = chrono::high_resolution_clock::now();
    for (long long r = 0; r < repeat; ++r)
    {
        for (int i = 0; i < n; ++i) work[i] = src[i];
        callSort(which, work, n, cmp, moves);
    }
    auto t1 = chrono::high_resolution_clock::now();
    return chrono::duration<double, micro>(t1 - t0).count() / (double)repeat;
}
 
/*==============================================================================
 * 模块2：冒泡排序（改进版）
 *------------------------------------------------------------------------------
 * 原理：反复遍历待排序区间，依次比较相邻两个元素，若逆序则交换，使较大的元素
 *       像气泡一样逐趟"浮"到区间末尾。每趟结束后，末尾的有序区长度 +1。
 * 改进：设置标志 swapped，若某一趟遍历中"没有发生任何元素交换"，说明整个序列
 *       已经有序，立即终止算法，不再进行多余的比较。
 * 时间复杂度：最好 O(n)（原始序列已有序，第 1 趟即终止）；最坏/平均 O(n^2)
 * 空间复杂度：O(1)，原地排序，稳定排序
 * 参数：cmp、moves 用引用返回，向调用者报告比较次数与移动次数
 *============================================================================*/
void bubbleSort(int a[], int n, long long &cmp, long long &moves)
{
    for (int i = 0; i < n - 1; ++i)                    // 共最多 n-1 趟
    {
        bool swapped = false;                          // 本趟是否发生交换
        for (int j = 0; j < n - 1 - i; ++j)            // 待排序区间 [0, n-1-i]
        {
            ++cmp;                                     // 统计一次比较
            if (a[j] > a[j + 1])                       // 逆序则交换
            {
                int t = a[j]; a[j] = a[j + 1]; a[j + 1] = t;
                moves += 3;                            // 一次交换记 3 次移动
                swapped = true;
            }
        }
        if (!swapped) break;                           // 本趟无交换 => 已有序，提前终止
    }
}
 
/*==============================================================================
 * 模块3：选择排序
 *------------------------------------------------------------------------------
 * 原理：把数组分成"已排序区"和"未排序区"。每一趟在未排序区中找出最小元素，
 *       与未排序区的第一个元素交换，然后已排序区长度 +1。
 * 特点：每趟固定比较 (n-1-i) 次，比较次数与数据初始状态无关，恒为 n(n-1)/2；
 *       但每趟最多交换 1 次，因此移动次数很少，只有 O(n) 量级。
 * 时间复杂度：最好/最坏/平均均为 O(n^2)
 * 空间复杂度：O(1)，原地排序，不稳定排序
 *============================================================================*/
void selectionSort(int a[], int n, long long &cmp, long long &moves)
{
    for (int i = 0; i < n - 1; ++i)
    {
        int minIdx = i;                                // 假定未排序区首元素最小
        for (int j = i + 1; j < n; ++j)
        {
            ++cmp;                                     // 统计一次比较
            if (a[j] < a[minIdx]) minIdx = j;          // 记录最小值下标
        }
        if (minIdx != i)                               // 只有需要时才交换
        {
            int t = a[i]; a[i] = a[minIdx]; a[minIdx] = t;
            moves += 3;
        }
    }
}
 
/*==============================================================================
 * 模块4：归并排序（分治法，"分解—合并"）
 *------------------------------------------------------------------------------
 * 合并函数 merge()：把已有序的 a[left..mid] 与 a[mid+1..right] 合并成一个有序
 *       区间。用两个游标分别指向两段开头，每次把较小者放入辅助数组 buf，最后
 *       把 buf 中的结果写回 a[left..right]，写回的每次赋值都计入移动次数。
 * 分解函数 mergeSortRec()：递归地把区间二分（分解），递归返回后再合并。
 * 时间复杂度：任何情况下均为 O(n log n)（每层合并总代价 O(n)，共 log n 层）
 * 空间复杂度：O(n)，需要辅助数组，稳定排序
 *============================================================================*/
void merge(int a[], int left, int mid, int right, long long &cmp, long long &moves)
{
    int i = left;          // 左半段游标
    int j = mid + 1;       // 右半段游标
    int k = left;          // 辅助数组写入位置
 
    while (i <= mid && j <= right)                     // 两段都没取完
    {
        ++cmp;                                         // 统计一次比较
        if (a[i] <= a[j])                              // "<=" 保证排序的稳定性
            buf[k++] = a[i++];
        else
            buf[k++] = a[j++];
        ++moves;                                       // 写入辅助数组记 1 次移动
    }
    while (i <= mid) { buf[k++] = a[i++]; ++moves; }    // 左段剩余元素直接搬走
    while (j <= right) { buf[k++] = a[j++]; ++moves; }  // 右段剩余元素直接搬走
 
    for (int p = left; p <= right; ++p)                 // 合并结果写回原数组
    {
        a[p] = buf[p];
        ++moves;                                       // 写回同样记 1 次移动
    }
}
 
void mergeSortRec(int a[], int left, int right, long long &cmp, long long &moves)
{
    if (left >= right) return;                         // 分解到只剩 1 个元素，天然有序
    int mid = (left + right) / 2;                      // 分解：取中点
    mergeSortRec(a, left, mid, cmp, moves);            // 递归排序左半段
    mergeSortRec(a, mid + 1, right, cmp, moves);       // 递归排序右半段
    merge(a, left, mid, right, cmp, moves);            // 合并两个有序子数组
}
 
void mergeSort(int a[], int n, long long &cmp, long long &moves)
{
    mergeSortRec(a, 0, n - 1, cmp, moves);
}
 
/*==============================================================================
 * 模块5（续）：结果输出与性能测试主流程
 *============================================================================*/
 
/* 打印数组片段：统一只打印前 20 个和后 10 个元素，中间用省略号代替，
 * 保证三种规模的截图宽度一致、重点突出。 */
void printSample(const char *tag, const int a[], int n)
{
    printf("  %s", tag);
    const int HEAD = 20, TAIL = 10;
    for (int i = 0; i < HEAD && i < n; ++i) printf("%7d", a[i]);
    if (n > HEAD + TAIL)
        printf("  ......(中间省略 %d 个元素)......", n - HEAD - TAIL);
    for (int i = (n > TAIL ? n - TAIL : HEAD); i < n; ++i) printf("%7d", a[i]);
    printf("\n");
}
 
/* 校验排序结果是否为非递减有序，用于验证算法实现的正确性 */
bool isSorted(const int a[], int n)
{
    for (int i = 1; i < n; ++i)
        if (a[i - 1] > a[i]) return false;
    return true;
}
 
const char *ALGO_NAME[3] = { "冒泡排序(改进版)", "选择排序", "归并排序" };
 
/* 对一种算法执行 3 次，输出比较次数、移动次数与平均执行时间。
 * 比较次数与移动次数只取决于算法与数据规模，与机器快慢无关，因此单独执行一次
 * 精确统计；执行时间则用"重复多次取平均"的方法测量并取 3 次的平均值。 */
void runAlgorithm(int which, const int src[], int n, long long repeat,
                  long long &cmp, long long &moves, double &us)
{
    int work[MAXN];
    for (int i = 0; i < n; ++i) work[i] = src[i];
    cmp = 0; moves = 0;
    callSort(which, work, n, cmp, moves);        // 单次排序，精确统计比较与移动次数
 
    double t1 = measureUs(which, src, n, repeat);
    double t2 = measureUs(which, src, n, repeat);
    double t3 = measureUs(which, src, n, repeat);
    us = (t1 + t2 + t3) / 3.0;
 
    printf("  第 1 次：比较次数 = %9lld   移动次数 = %9lld   平均执行时间 = %10.3f 微秒\n", cmp, moves, t1);
    printf("  第 2 次：比较次数 = %9lld   移动次数 = %9lld   平均执行时间 = %10.3f 微秒\n", cmp, moves, t2);
    printf("  第 3 次：比较次数 = %9lld   移动次数 = %9lld   平均执行时间 = %10.3f 微秒\n", cmp, moves, t3);
    printf("  (计时方式：同一随机数组连续排序 %lld 次取平均；比较/移动次数按单次排序统计)\n", repeat);
}
 
/* 把标准输出切换为 UTF-8 编码，保证中文在控制台、重定向文件与截图中都不乱码。 */
static void setupUtf8Output()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);        // 控制台按 UTF-8 解释输出字节
#endif
}
 
int main()
{
    setupUtf8Output();
    const int SCALE[3] = { 100, 1000, 10000 };         // 三种数据规模
    const long long REPEAT[3] = { 500, 50, 1 };        // 计时重复次数：规模越大重复越少
 
    printf("============================================================\n");
    printf("   实验一  冒泡 / 选择 / 归并 排序算法性能测试\n");
    printf("   数据范围: [1, 100000] 的随机整数, 每种规模重复 3 次取平均\n");
    printf("   时间统计: C++11 <chrono> 高精度时钟 (微秒)\n");
    printf("============================================================\n");
 
    for (int s = 0; s < 3; ++s)
    {
        const int n = SCALE[s];
        int src[MAXN];
        genRandomArray(src, n, 20250809u + (unsigned)n);
        printf("\n############################################################\n");
        printf("# 数据规模 n = %d\n", n);
        printf("############################################################\n");
        printSample("排序前片段:", src, n);
 
        for (int which = 0; which < 3; ++which)
        {
            long long cmp = 0, moves = 0;
            double us = 0;
            printf("\n  ---------- %s (3 次运行) ----------\n", ALGO_NAME[which]);
            runAlgorithm(which, src, n, REPEAT[s], cmp, moves, us);
 
            int check[MAXN];                       // 单独跑一次用于展示排序结果
            for (int i = 0; i < n; ++i) check[i] = src[i];
            long long c2 = 0, m2 = 0;
            callSort(which, check, n, c2, m2);
            printf("  单独执行一次用于展示排序结果：\n");
            printSample("排序后片段:", check, n);
 
            printf("  >>> %s 平均: 比较次数 = %lld, 移动次数 = %lld, 执行时间 = %.3f 微秒\n",
                   ALGO_NAME[which], cmp, moves, us);
            printf("  >>> 一致性校验: 排序结果%s\n",
                   isSorted(check, n) ? "非递减有序 (正确)" : "错误");
        }
    }
    printf("\n测试全部完成。\n");
    return 0;
}
