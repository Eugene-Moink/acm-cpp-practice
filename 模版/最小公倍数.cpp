#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/* =====================================================
预处理模板：素数筛（埃氏筛）
【用途】预处理出 [0, n] 范围内的所有素数，存入全局数组 primes。
【参数】n (int): 筛的上限。通常取 sqrt(最大待分解数)。如数据范围 1e9，取 31623。
【复杂度】时间复杂度 O(n log log n)，空间复杂度 O(n)。
===================================================== */
const int MAX_SQRT = 100000;
vector<int> primes;
bool is_prime[MAX_SQRT + 1];

void init_primes(int n)
{
    fill(is_prime, is_prime + n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; ++i)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
            if (1LL * i * i <= n)
            {
                for (int j = i * i; j <= n; j += i)
                {
                    is_prime[j] = false;
                }
            }
        }
    }
}

/* =====================================================
运算模板：质因数分解
【用途】将正整数 x 分解为质因数的幂次乘积。
【参数】x (ll): 待分解的整数。
【返回值】unordered_map<ll, ll>: key为质因子，value为对应的指数。
【前置条件】必须先调用 init_primes(sqrt(最大值)) 预处理出素数表。
【复杂度】时间复杂度 O(sqrt(x) / log x)。
===================================================== */
unordered_map<ll, ll> factorize(ll x)
{
    unordered_map<ll, ll> exp;
    for (int p : primes)
    {
        if (1LL * p * p > x)
            break;
        if (x % p == 0)
        {
            int cnt = 0;
            while (x % p == 0)
            {
                x /= p;
                cnt++;
            }
            exp[p] = cnt;
        }
    }
    if (x > 1)
        exp[x] = 1;
    return exp;
}

/* =====================================================
运算模板：快速幂（模运算）
【用途】计算 base 的 exp 次幂对 mod 取模的结果。
【参数】base (ll): 底数；exp (ll): 指数；mod (ll): 模数。
【复杂度】时间复杂度 O(log exp)，空间复杂度 O(1)。
===================================================== */
ll fast_pow(ll base, ll exp, ll mod)
{
    ll res = 1;
    base %= mod;
    while (exp > 0)
    {
        if (exp & 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

/* =====================================================
通用问题模板：求一组数的最小公倍数（LCM）
【用途】给定一个整数数组，求出它们的最小公倍数，并对 mod 取模。
【参数】nums (vector<ll>&): 数组；mod (ll): 模数。
【返回值】ll: 最小公倍数模 mod 的结果。
【核心思想】LCM = 所有质因子在数组中出现的最大指数的乘积。
【复杂度】时间复杂度 O(n * sqrt(x) / log x)，空间复杂度 O(质因子个数)。
===================================================== */
ll get_lcm_mod(const vector<ll> &nums, ll mod)
{
    unordered_map<ll, ll> max_exp;
    for (ll x : nums)
    {
        unordered_map<ll, ll> cur_exp = factorize(x);
        for (auto &kv : cur_exp)
        {
            max_exp[kv.first] = max(max_exp[kv.first], kv.second);
        }
    }

    ll ans = 1;
    for (auto &kv : max_exp)
    {
        ans = (ans * fast_pow(kv.first, kv.second, mod)) % mod;
    }
    return ans;
}

/* ==================== 调用示例 ==================== */
const ll MOD = 998244353;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init_primes(31623); // 假设数据范围 ≤ 1e9，sqrt(1e9) ≈ 31623

    int n;
    cin >> n;
    vector<ll> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    // 直接调用 LCM 模板
    cout << get_lcm_mod(nums, MOD) << endl;

    return 0;
}