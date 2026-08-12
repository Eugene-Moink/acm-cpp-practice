#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string process_line(const string &s)
{
    string res;
    for (char c : s)
    {
        if (c == '<')
        {
            if (!res.empty())
                res.pop_back();
        }
        else
            res.push_back(c);
    }
    return res;
}

vector<string> read_text()
{
    vector<string> line;
    string s;
    while (getline(cin, s))
    {
        if (s == "EOF")
            break;
        line.push_back(process_line(s));
    }
    return line;
}

void moink()
{
    vector<string> text = read_text();
    vector<string> input = read_text();

    int t;
    cin >> t;

    int right = 0;
    int row = min(text.size(), input.size());
    for (int i = 0; i < row; i++)
    {
        int col = min(text[i].size(), input[i].size());
        for (int j = 0; j < col; j++)
        {
            if (text[i][j] == input[i][j])
                right++;
        }
    }

    int ans = (int)((double)right * 60 / t + 0.5);
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}