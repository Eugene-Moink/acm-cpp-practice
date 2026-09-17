/**
 * @brief 定长区间加权和 O(1) 滑动转移
 * @note val_new = val_old - sum_old + m * a[l+m]
 *       sum_new = sum_old - a[l] + a[l+m]
 * @warn 先更新val再更新sum; 全long long; 权重反向时改为 val+sum-m*a[l]
 */

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