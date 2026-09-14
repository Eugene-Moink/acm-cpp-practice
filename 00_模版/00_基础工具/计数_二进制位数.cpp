int bit_length(ll n)
{
    int len = 0;
    while (n > 0)
    {
        len++;
        n >>= 1;
    }
    return len;
}