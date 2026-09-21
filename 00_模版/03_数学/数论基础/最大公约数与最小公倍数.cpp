ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    if (a == 0 || b == 0)
        return 0;
    return a / gcd(a, b) * b;
}