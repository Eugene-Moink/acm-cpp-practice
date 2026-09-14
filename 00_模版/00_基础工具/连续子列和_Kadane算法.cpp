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