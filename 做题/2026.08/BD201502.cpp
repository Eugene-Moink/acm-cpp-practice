#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    string s;
    int k;
    while (getline(cin, s))
    {
        if (s.empty())
            continue;

        cin >> k;
        cin.ignore();

        int n = s.size();
        int rows = (n + k - 1) / k;
        int last = n - (rows - 1) * k;

        vector<vector<char>> mat(rows, vector<char>(k, '\0'));

        int pos = 0;
        for (int j = 0; j < k; j++)
        {
            int col_len = (j < last) ? rows : rows - 1;
            for (int i = 0; i < col_len; i++)
            {
                mat[i][j] = s[pos++];
            }
        }

        string ans;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < k; j++)
            {
                if (mat[i][j] != '\0')
                    ans += mat[i][j];
            }
        }
        cout << ans << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}