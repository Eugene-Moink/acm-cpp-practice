/* =====================================================
定长滑动窗口加权和

【用途】
  长为 m 的窗口内求 Σ a[i] * (i - l + 1) 的最大值，即权重从左到右递增的加权和。
【输入】
  a：vector<ll>；m：窗口长度。
【输出】
  ll，最大加权和；n < m 时返回 -1e18。
【复杂度】
  O(n)，每次滑动转移 O(1)。
【易错提醒】
  1. 必须先更新 val 再更新 sum，顺序反了结果会错。
  2. 全程用 long long，val 会超出 int 范围。
  3. 权重方向相反（从右往左递增）时，递推改成 val + sum - m * a[l]。
  4. n < m 时返回 -1e18，调用方需要自行判断是否无解。
===================================================== */

ll max_Wgt_Sum(const std::vector<ll> &a, int m)
{
    int n = static_cast<int>(a.size());
    if (n < m)
        return -1e18;

    ll sum = 0, val = 0;
    for (int i = 0; i < m; i++)
    {
        sum += a[i];
        val += a[i] * (i + 1);
    }

    ll ans = val;
    for (int l = 0; l + m < n; l++)
    {
        val = val - sum + a[l + m] * m;
        sum = sum - a[l] + a[l + m];
        ans = std::max(ans, val);
    }

    return ans;
}