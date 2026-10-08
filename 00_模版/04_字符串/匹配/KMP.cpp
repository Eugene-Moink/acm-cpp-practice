/* =====================================================
KMP 字符串匹配

【用途】
  在文本串 s 中查找模式串 p 的所有出现位置。
【输入】
  s（文本串）、p（模式串）。
【输出】
  vector<int>，所有匹配起点（0-based，升序）。
【复杂度】
  预处理 O(|p|)，匹配 O(|s|)，总计 O(|s| + |p|)。
【易错提醒】
  1. nxt[i] 表示 p[0..i] 的最长公共前后缀长度，本文件是 0-based 写法，别和 1-based 混用。
  2. 匹配成功一次后要写 j = nxt[j - 1]，才能找出重叠出现。
  3. p 为空串必须特判，否则 p[j] 越界。
  4. 求最小循环节用 n − nxt[n−1]，并要求 n % (n − nxt[n−1]) == 0。
  5. 多组数据：在 main 里取消 // cin >> T; 的注释。
===================================================== */

vector<int> get_next(const string &p)
{
    int m = p.size();
    vector<int> nxt(m, 0);

    for (int i = 1; i < m; i++)
    {
        int j = nxt[i - 1];
        while (j > 0 && p[i] != p[j])
            j = nxt[j - 1];
        if (p[i] == p[j])
            j++;
        nxt[i] = j;
    }
    return nxt;
}

vector<int> kmp(const string &s, const string &p)
{
    vector<int> res;
    if (p.empty())
        return res;

    vector<int> nxt = get_next(p);
    int j = 0;

    for (int i = 0; i < (int)s.size(); i++)
    {
        while (j > 0 && s[i] != p[j])
            j = nxt[j - 1];
        if (s[i] == p[j])
            j++;
        if (j == (int)p.size())
        {
            res.push_back(i - j + 1);
            j = nxt[j - 1];
        }
    }
    return res;
}

void solve()
{
    string s, p;
    if (!(cin >> s >> p))
        return;

    vector<int> pos = kmp(s, p);
    cout << pos.size() << "\n";
    for (int x : pos)
        cout << x << " ";
    cout << "\n";
}