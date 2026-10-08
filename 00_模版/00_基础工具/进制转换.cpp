/* =====================================================
任意进制互转（三种写法合订）

【用途】
  x 进制字符串 → 十进制整数：parseBase(num, base)
  十进制整数   → n 进制字符串：toBase(num, base)
  n 进制字符串 → m 进制字符串：convertBase(num, fromBase, destBase)（前两者串联）
【输入】
  num：字符串；base / fromBase / destBase：2..36 的整数。
【输出】
  parseBase 返回 ll（非法输入返回 -1）；toBase / convertBase 返回大写数字串。
【复杂度】
  三种写法均为 O(L)，L 为字符串长度。
【易错提醒】
  1. 字符映射：0-9 → 0-9，A-Z / a-z → 10-35，读入不区分大小写，输出统一大写。
  2. 输入 "0" 时 toBase 返回 "0"；漏掉 num == 0 的特判会输出空串（旧版写法即有此 bug）。
  3. 仅支持非负整数，负数需自行加符号逻辑。
  4. 数值超过 2^63-1（ll 上限）时需改用高精度算法（如 Python 或手写大数）。
  5. 判断非法输入：parseBase 返回 -1 表示出现了 >= base 的数码。
  6. 循环里不要用 pow() 累加权重，直接用 res = res * base + d 更安全。
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
