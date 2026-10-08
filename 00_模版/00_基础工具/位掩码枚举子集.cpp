/* =====================================================
位掩码枚举子集模板

【用途】
  1. 枚举 [0, n) 的全部非空子集：for (int mask = 1; mask < (1 << n); ++mask)。
  2. 枚举某个 mask 的全部子集：for (int sub = mask; sub; sub = (sub - 1) & mask)。
  3. 用 __builtin_popcount 统计 1 的个数、lowbit = x & -x 取最低位 1 的值。

【输入】
  场景 1：元素个数 n，或直接从给定数组 a 的位掩码出发。
  场景 2：一个已经确定的 mask（int）。
  场景 3：非负整数 x（ll）。

【输出】
  场景 1：每个 mask 对应一个子集，按 mask 递增顺序访问；enumerate_all_subsets 返回「最大子集和」作为可运行的落点。
  场景 2：mask 的每个子集（不含 mask 本身，空集需要单独处理）。
  场景 3：1 的个数（int）、最低位 1 对应的数值（ll）、最高位 1 的下标（int）。

【复杂度】
  场景 1：O(2^n * n)（含逐位检查），只枚举 mask 本身是 O(2^n)。
  场景 2：O(3^n)（所有 mask 的子集总数），单个 mask 是 O(2^popcount(mask))。
  场景 3：O(1)。

【易错提醒】
  1. 1 << n 在 n >= 31 时溢出（有符号位移是未定义行为，实际会得到负数），必须改用 1LL << n；数组大小也要相应改成 1LL << n 个元素（n <= 20 ~ 22 才是实用范围）。
  2. 就算改成 1LL << n，n >= 63 时 1LL << n 同样未定义；n >= 63 只能折半枚举（meet in the middle）。
  3. 场景 2 的循环 sub = mask 起手会把 mask 自己先访问一遍，不需要就把起手写成 sub = (mask - 1) & mask；循环退出后还有一个空集要单独处理（空集是任何 mask 的子集）。
  4. 用 int 做 mask 时 n <= 30，用 ll 做 mask 时 n <= 62，别混用。
  5. 位测试用 (mask >> i) & 1 或 (mask >> i & 1)，注意 & 优先级低于 >>，所以 (mask >> i) & 1 最稳。
  6. x == 0 时 __builtin_ctzll / __builtin_clzll 是未定义行为，必须特判。
===================================================== */

/* ==================== 一、枚举全部子集 ==================== */

ll enumerate_all_subsets(const vector<ll> &a)
{
    int n = (int)a.size();
    ll best = 0;
    for (int mask = 1; mask < (1 << n); ++mask)
    {
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            if ((mask >> i) & 1)
                sum += a[i];
        }
        best = max(best, sum);
    }
    return best;
}

/* ==================== 二、枚举某个 mask 的所有子集 ==================== */

void enumerate_submasks(int mask)
{
    for (int sub = mask; sub; sub = (sub - 1) & mask)
    {
        int visit = sub;
        (void)visit;
    }
    int empty = 0;
    (void)empty;
}

void enumerate_submasks_no_self(int mask)
{
    for (int sub = (mask - 1) & mask; sub; sub = (sub - 1) & mask)
    {
        int visit = sub;
        (void)visit;
    }
    int empty = 0;
    (void)empty;
}

/* ==================== 三、popcount 与 lowbit ==================== */

int count_ones(int x)
{
    return __builtin_popcount((unsigned)x);
}

int count_ones_ll(ll x)
{
    return __builtin_popcountll((unsigned long long)x);
}

ll lowbit(ll x)
{
    return x & -x;
}

int high_bit_index(ll x)
{
    if (x <= 0)
        return -1;
    return 63 - __builtin_clzll((unsigned long long)x);
}

int low_bit_index(ll x)
{
    if (x <= 0)
        return -1;
    return __builtin_ctzll((unsigned long long)x);
}

/* ==================== 调用示例（贴进自己的 main） ====================
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << enumerate_all_subsets(a) << "\n";   // 返回非空子集的最大子集和，不需要返回值直接忽略即可

    int mask = 0b1011;                          // n = 4 时的一个子集
    enumerate_submasks(mask);                   // 含 mask 自己与空集
    enumerate_submasks_no_self(mask);           // 不含 mask 自己（空集仍需单独处理）

    ll x;
    cin >> x;
    cout << count_ones_ll(x) << " " << lowbit(x) << "\n";
    cout << low_bit_index(x) << " " << high_bit_index(x) << "\n";

    // n = 3 时 mask 依次为 001 010 011 100 101 110 111（跳过空集 000）
    // mask = 0b1011 -> 子集：1011 1010 1001 1000 0011 0010 0001 0000（含自身与空集）
    // x = 0b101100 -> popcount = 3，lowbit = 4，最低位下标 = 2，最高位下标 = 5
==================================================================== */
