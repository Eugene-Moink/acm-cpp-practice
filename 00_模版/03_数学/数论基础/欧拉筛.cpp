/* =====================================================
欧拉筛（线性筛素数）

【用途】
  筛出 [2, n] 内的所有素数；每个合数只被其最小质因子筛掉一次。
【输入】
  n (int)，上界。
【输出】
  全局 is_prime[]（素性标记）与 prime[]（素数表，0-based）。
【复杂度】
  O(n)。
【易错提醒】
  1. 防溢出：循环条件必须写 1LL * i * prime[j] <= n，不能写 i * prime[j] <= n。
  2. 判断素性用 is_prime[v]，取第 k 个素数用 prime[k - 1]。
  3. sieve(n) 内部已重置 is_prime 与 prime，多组数据可以直接重新调用。
  4. n < 2 时素数表为空，调用方需要自己特判。
===================================================== */
vector<bool> is_prime;
vector<int> prime;

void sieve(int n)
{
    is_prime.assign(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    prime.clear();

    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
            prime.push_back(i);

        for (int j = 0; j < (int)prime.size() && 1LL * i * prime[j] <= n; j++)
        {
            is_prime[i * prime[j]] = false;
            if (i % prime[j] == 0)
                break;
        }
    }
}

void solve()
{
    int n, q;
    if (!(cin >> n >> q))
        return;

    sieve(n);

    while (q--)
    {
        int k;
        cin >> k;
        cout << prime[k - 1] << "\n";
    }
}
