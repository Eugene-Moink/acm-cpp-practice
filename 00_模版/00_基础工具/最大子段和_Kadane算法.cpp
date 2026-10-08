/* =====================================================
最大子段和（Kadane 算法）

【用途】
  求数组连续子段的最大和，允许负数。
【输入】
  a：vector<ll>。
【输出】
  ll，最大子段和；数组全为负数时返回其中最大的单个元素。
【复杂度】
  O(n)。
【易错提醒】
  1. best 必须初始化为 LLONG_MIN，不能初始化成 0，否则全负数数组会返回 0。
  2. 等价写法：`cur = max(cur + x, x); best = max(best, cur);`，这种写法不需要额外清零。
  3. 要求子段非空时用上面的写法；允许空子段才把 best 初始化成 0。
===================================================== */
ll max_subarray_sum(const vector<ll> &a)
{
    ll cur = 0;
    ll best = LLONG_MIN;

    for (ll x : a)
    {
        cur += x;
        if (cur > best)
        {
            best = cur;
        }
        if (cur < 0)
        {
            cur = 0;
        }
    }
    return best;
}