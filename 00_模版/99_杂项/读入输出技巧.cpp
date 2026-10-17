/* =====================================================
读入输出技巧

【用途】
  一整组「读入 / 输出」上的高频踩坑与写法：混用 cin 与 getline、整行读入、
  字符串大数边读边取模、大数比较、浮点输出、快速 IO。
【输入】
  按各函数说明。
【输出】
  按各函数说明。
【复杂度】
  均 O(串长)；快速 IO 只是常数优化。
【易错提醒】
  1. `cin >> x` 之后紧接着 `getline(cin, s)` 会读到一个空串（残留换行）——
     必须先 `ignore_line()`。这是混用两种读入最常见的 bug。
  2. 读整行含空格用 getline；getline 本身不会跳过前导空格，题目要求「跳过前导空格」时自己 trim。
  3. 读到 EOF 的写法：`while (getline(cin, line))` 与 `while (cin >> x)`，注意空行会让 getline 返回空串但不算 EOF。
  4. 字符串大数（超过 2^63）不要 stoll：按位边读边取模即可；比较大小先比长度再比字典序。
  5. `endl` 会 flush，海量输出用 `'\n'`；`cin.tie(nullptr)` 只是解除绑定，不是加速读入的万能药。
  6. 浮点输出必须 `fixed` + `setprecision(k)`，否则默认有效数字会丢精度。
  7. 本地调试 freopen 记得在提交时注释掉，或用宏包一层。
===================================================== */

/* 清掉当前行剩余内容（含换行），用于 cin >> 与 getline 混用之前 */
void ignore_line()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/* 字符串大数边读边取模：n 可以是几千位 */
ll big_str_mod(const string &s, ll mod)
{
    ll r = 0;
    for (char c : s)
    {
        if (c < '0' || c > '9')
        {
            continue;
        }
        r = (r * 10 + (c - '0')) % mod;
    }
    return r;
}

/* 大整数比较：先比长度（去前导零），长度相同再比字典序 */
bool big_less(const string &x, const string &y)
{
    auto strip = [](const string &s)
    {
        size_t p = s.find_first_not_of('0');
        return p == string::npos ? string("0") : s.substr(p);
    };
    string a = strip(x), b = strip(y);
    if (a.size() != b.size())
    {
        return a.size() < b.size();
    }
    return a < b;
}

/* 浮点输出固定小数位 */
void print_fixed(double x, int k)
{
    cout << fixed << setprecision(k) << x << "\n";
}

/* 快速 IO（放在 main 开头） */
void fast_io()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

/* ==================== 调用示例（贴进自己的 main） ====================
    fast_io();

    int T;
    cin >> T;
    ignore_line();                 // 关键：把 T 后面的换行吃掉

    for (int i = 0; i < T; i++)
    {
        string line;
        getline(cin, line);        // 整行读入（可能含空格）
        cout << line.size() << "\n";
    }

    // 大数取模
    string big;
    cin >> big;
    cout << big_str_mod(big, 1000000007) << "\n";

    // 大数比较
    string a, b;
    cin >> a >> b;
    cout << (big_less(a, b) ? "a < b" : "a >= b") << "\n";

    print_fixed(1.0 / 3.0, 6);     // 0.333333
   ==================================================================== */
