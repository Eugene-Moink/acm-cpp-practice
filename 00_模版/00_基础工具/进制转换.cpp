/* =====================================================
任意进制互转模板（三种写法合订）

【写法一】x 进制字符串 -> 十进制整数     parseBase(num, base)
【写法二】十进制整数   -> n 进制字符串   toBase(num, base)
【写法三】n 进制字符串 -> m 进制字符串   convertBase(num, fromBase, destBase)
                                       （写法一 + 写法二 串联）

【字符映射规则】
  0-9 对应 0-9，A-Z 对应 10-35，a-z 对应 10-35（读入不区分大小写，输出统一大写）。

【复杂度】
  三种写法均为 O(L)，L 为字符串长度。

【易错提醒】
  1. 输入 "0" 时 toBase 返回 "0"；漏掉 num == 0 的特判会输出空串（旧版写法即有此 bug）。
  2. 仅支持非负整数，负数需自行加符号逻辑。
  3. 数值超过 2^63-1（ll 上限）时需改用高精度算法（如 Python 或手写大数）。
  4. 判断非法输入：parseBase 返回 -1 表示出现了 >= base 的数码。
  5. 循环里不要用 pow() 累加权重，直接用 res = res * base + d 更安全。
===================================================== */

/* ==================== 写法一：x 进制 -> 十进制 ==================== */

int charToInt(char c)
{
    if ('0' <= c && c <= '9')
        return c - '0';
    if ('A' <= c && c <= 'Z')
        return c - 'A' + 10;
    if ('a' <= c && c <= 'z')
        return c - 'a' + 10;
    return -1;
}

ll parseBase(const string &num, int base)
{
    ll res = 0;
    for (char c : num)
    {
        int d = charToInt(c);
        if (d < 0 || d >= base)
            return -1;
        res = res * base + d;
    }
    return res;
}

/* ==================== 写法二：十进制 -> n 进制 ==================== */

char intToChar(int d)
{
    if (d < 10)
        return '0' + d;
    return 'A' + (d - 10);
}

string toBase(ll num, int base)
{
    if (num == 0)
        return "0";

    string out;
    while (num > 0)
    {
        out.push_back(intToChar(num % base));
        num /= base;
    }
    reverse(out.begin(), out.end());
    return out;
}

/* ==================== 写法三：n 进制 -> m 进制 ==================== */

string convertBase(const string &num, int fromBase, int destBase)
{
    ll temp = parseBase(num, fromBase);
    if (temp == -1)
        return "Invalid input";
    return toBase(temp, destBase);
}

/* ==================== 调用示例（贴进自己的 main） ====================
    ll n, m;
    string num;
    cin >> n >> num;   // 源进制 n，数字字符串 num
    cin >> m;          // 目标进制 m
    cout << convertBase(num, (int)n, (int)m) << "\n";

    // 16 FF 10          -> 255
    // 10 0 2            -> 0
    // 2 1010 16         -> A
    // 2 1012 10         -> Invalid input
    // 36 ZZZ 10         -> 46655
==================================================================== */
