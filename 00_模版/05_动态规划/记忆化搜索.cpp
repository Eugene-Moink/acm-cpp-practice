/*
 * 记忆化搜索
 *
 * 【用途】把「递归 + 重叠子问题」用缓存加速：算过的状态直接查表，不再重复递归。
 *         示例一（数组型）：数的划分，f(n, k) = 把 n 拆成 k 个正整数之和的方案数（不计顺序）；
 *         示例二（map 型）：整除降数，f(n) = 每次把 n 整除 2 或整除 3，变成不超过 1 的最少次数，n 可以到 1e18。
 * 【输入】partition_count 传入 n、k（要求 0 <= n < PART_N、0 <= k < PART_K）；min_step_count 传入 n（ll，任意大）
 * 【输出】方案数 / 最少次数（ll）
 * 【复杂度】状态数乘单状态转移代价；数组版 O(n * k) 状态、转移 O(1)；
 *           map 版可达状态只有 O(log^2 n) 个，每个状态一次 O(log(状态数)) 的查找
 * 【易错提醒】1. -1 作哨兵时状态本身不能取到 -1：本模板 f 的取值都是非负整数才安全，有合法 -1 时改用 vis 数组标记；
 *             2. 数的划分 f(0, 0) = 1 是递推边界，而 k <= 0、k > n 时要返回 0，两个边界判断的先后顺序不能反；
 *             3. map 版常数远大于数组：状态能开数组就别用 map，unordered_map 版本还多一次哈希与可能的重哈希；
 *             4. 递归层数深时会爆栈（例如一维状态 n = 1e5 的写法），改写成递推，或编译时用 -Wl,--stack=... 加大栈；
 *             5. 多组数据必须重置：数组用 memset / fill 清回 -1，map 用 clear()，否则上一组的答案会被当成本组的结果；
 *             6. 数组版的状态范围受 PART_N、PART_K 限制，n 或 k 超出时要么调大常量，要么换成 map 版。
 *
 * 多组数据：partition_count、min_step_count 每次调用前都会自动重置缓存，也可以先手动 reset_memo()。
 */

const int PART_N = 205;
const int PART_K = 205;

ll memo[PART_N][PART_K];

/* ==================== 一、数组型记忆化：数的划分 f(n, k)（memo 里 -1 表示还没算过） ==================== */

ll dfs(int n, int k)
{
    if (n == 0 && k == 0)
    {
        return 1;
    }
    if (n <= 0 || k <= 0 || k > n)
    {
        return 0;
    }
    if (memo[n][k] != -1)
    {
        return memo[n][k];
    }

    ll res = dfs(n - 1, k - 1) + dfs(n - k, k);
    memo[n][k] = res;
    return res;
}

ll partition_count(int n, int k)
{
    memset(memo, -1, sizeof(memo));

    if (n < 0 || k < 0)
    {
        return 0;
    }
    return dfs(n, k);
}

/* ==================== 二、map / unordered_map 缓存版：状态值很大或状态稀疏，开不了数组 ==================== */

map<ll, ll> memo_map;

ll dfs_map(ll n)
{
    if (n <= 1)
    {
        return 0;
    }

    auto it = memo_map.find(n);
    if (it != memo_map.end())
    {
        return it->second;
    }

    ll res = 1 + min(dfs_map(n / 2), dfs_map(n / 3));
    memo_map[n] = res;
    return res;
}

ll min_step_count(ll n)
{
    memo_map.clear();

    if (n < 0)
    {
        return 0;
    }
    return dfs_map(n);
}

/* ==================== 三、多组数据必须重置 ====================
 *   数组版：memset(memo, -1, sizeof(memo))（-1 的每个字节都是 0xFF，对 ll 同样成立；哨兵是 0 时改成 memset(..., 0, ...)；
 *           vector 版本用 fill(v.begin(), v.end(), -1LL) 或 v.assign(size, -1LL)）；
 *   map 版：memo_map.clear()；
 *   忘记重置的典型症状：第二组数据比第一组小，却算出上一组留下来的更大答案。
 * ==================== */

void reset_memo()
{
    memset(memo, -1, sizeof(memo));
    memo_map.clear();
}

/* ==================== 调用示例（贴进自己的 main） ====================
    int n, k;
    cin >> n >> k;
    cout << partition_count(n, k) << "\n";       // 把 n 拆成 k 个正整数之和的方案数，如 (6, 3) -> 3

    ll x;
    cin >> x;
    cout << min_step_count(x) << "\n";           // 每次整除 2 或 3 变到 <= 1 的最少次数，如 1e18 -> 38（38 次除 3 即可）

    // 多组询问：partition_count / min_step_count 内部已经重置过 memo，与先调一次 reset_memo() 等价
    // 若自己直接调 dfs / dfs_map，就必须在换组数据前手动重置
    ==================================================================== */
