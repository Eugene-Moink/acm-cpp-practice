/*
 * Z 函数（扩展 KMP）
 *
 * 定义：z[i] = s 与 s[i..] 的最长公共前缀长度（z[0] = 0）
 *
 * 用途：字符串匹配、求循环节、判断前缀出现的所有位置
 * 复杂度：O(N)
 *
 * 多组数据：取消 main 中 // cin >> T; 的注释
 */
vector<int> z_function(const string &s)
{
    int n = s.size();
    vector<int> z(n, 0);

    int l = 0, r = 0;
    for (int i = 1; i < n; i++)
    {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] - 1 > r)
        {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

vector<int> kmp_via_z(const string &s, const string &p)
{
    vector<int> res;
    string t = p + "#" + s;
    vector<int> z = z_function(t);
    int m = p.size();

    for (int i = m + 1; i < (int)t.size(); i++)
    {
        if (z[i] == m)
            res.push_back(i - m - 1);
    }
    return res;
}

void solve()
{
    string s, p;
    if (!(cin >> s >> p))
        return;

    vector<int> pos = kmp_via_z(s, p);
    cout << pos.size() << "\n";
    for (int x : pos)
        cout << x << " ";
    cout << "\n";
}