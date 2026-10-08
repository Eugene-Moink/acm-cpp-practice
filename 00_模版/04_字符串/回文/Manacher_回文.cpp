/* =====================================================
Manacher 最长回文子串

【用途】
  O(N) 求最长回文子串长度，以及以每个位置为中心的最长回文半径。
【输入】
  s（字符串）；longest_palindrome(s) 直接吃原串。
【输出】
  int，最长回文子串的长度。
【复杂度】
  O(N)。
【易错提醒】
  1. 技巧：插入 '#' 把奇偶长度回文统一处理，例如 "abcba" → "#a#b#c#b#a#"。
  2. preprocess 两端补 '^' 与 '$' 哨兵，避免 while 越界，不要删。
  3. manacher 返回的 p[] 是插 '#' 之后的半径，求原串长度直接取 max(p) 即可。
  4. 多组数据：在 main 里取消 // cin >> T; 的注释。
===================================================== */

string preprocess(const string &s)
{
    string t = "^#";
    for (char c : s)
    {
        t += c;
        t += '#';
    }
    t += '$';
    return t;
}

vector<int> manacher(const string &s)
{
    string t = preprocess(s);
    int n = t.size();
    vector<int> p(n, 0);

    int c = 0, r = 0;
    for (int i = 1; i < n - 1; i++)
    {
        int mirror = 2 * c - i;
        if (i < r)
            p[i] = min(r - i, p[mirror]);

        while (t[i + p[i] + 1] == t[i - p[i] - 1])
            p[i]++;

        if (i + p[i] > r)
        {
            c = i;
            r = i + p[i];
        }
    }
    return p;
}

int longest_palindrome(const string &s)
{
    vector<int> p = manacher(s);
    int ans = 0;
    for (int x : p)
        ans = max(ans, x);
    return ans;
}

void solve()
{
    string s;
    if (!(cin >> s))
        return;

    cout << longest_palindrome(s) << "\n";
}