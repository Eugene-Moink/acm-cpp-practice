/*
 * Manacher 最长回文子串
 *
 * 用途：O(N) 求最长回文子串长度、以每个位置为中心的最长回文半径
 * 复杂度：O(N)
 *
 * 技巧：在字符串中插入 '#'，把奇数长和偶数长回文统一处理
 *       例如 "abcba" → "#a#b#c#b#a#"
 *
 * 多组数据：取消 main 中 // cin >> T; 的注释
 */

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