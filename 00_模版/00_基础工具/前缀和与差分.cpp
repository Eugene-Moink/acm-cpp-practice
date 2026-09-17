void solve()
{
    // ==================== 一维前缀和 ====================
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<ll> pref(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        pref[i] = pref[i - 1] + a[i - 1];
    }

    // 查询区间 [l, r] 的和（1-based）
    int l, r;
    cin >> l >> r;
    cout << pref[r] - pref[l - 1] << "\n";

    // ==================== 一维差分 ====================
    // 给区间 [l, r] 每个数加 val
    vector<ll> diff(n + 2, 0);
    int q;
    cin >> q;
    while (q--)
    {
        int L, R;
        ll val;
        cin >> L >> R >> val;
        diff[L] += val;
        diff[R + 1] -= val;
    }

    // 还原数组
    vector<ll> restored(n, 0);
    ll cur = 0;
    for (int i = 0; i < n; i++)
    {
        cur += diff[i];
        restored[i] = a[i] + cur;
    }
    for (int i = 0; i < n; i++)
        cout << restored[i] << " ";
    cout << "\n";

    // ==================== 二维前缀和 ====================
    int H, W;
    cin >> H >> W;
    vector<vector<ll>> grid(H, vector<ll>(W));
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            cin >> grid[i][j];

    vector<vector<ll>> pref2(H + 1, vector<ll>(W + 1, 0));
    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            pref2[i][j] = pref2[i - 1][j] + pref2[i][j - 1] - pref2[i - 1][j - 1] + grid[i - 1][j - 1];
        }
    }

    // 查询子矩阵 (x1, y1) 到 (x2, y2) 的和（1-based）
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << pref2[x2][y2] - pref2[x1 - 1][y2] - pref2[x2][y1 - 1] + pref2[x1 - 1][y1 - 1] << "\n";

    // ==================== 二维差分 ====================
    // 给子矩阵 (x1, y1) 到 (x2, y2) 每个数加 val
    vector<vector<ll>> diff2(H + 2, vector<ll>(W + 2, 0));
    int q2;
    cin >> q2;
    while (q2--)
    {
        int X1, Y1, X2, Y2;
        ll val;
        cin >> X1 >> Y1 >> X2 >> Y2 >> val;
        diff2[X1][Y1] += val;
        diff2[X1][Y2 + 1] -= val;
        diff2[X2 + 1][Y1] -= val;
        diff2[X2 + 1][Y2 + 1] += val;
    }

    // 还原矩阵
    vector<vector<ll>> ans2(H, vector<ll>(W, 0));
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            ans2[i][j] = diff2[i][j];
            if (i > 0)
                ans2[i][j] += ans2[i - 1][j];
            if (j > 0)
                ans2[i][j] += ans2[i][j - 1];
            if (i > 0 && j > 0)
                ans2[i][j] -= ans2[i - 1][j - 1];
        }
    }
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
            cout << ans2[i][j] << " ";
        cout << "\n";
    }
}