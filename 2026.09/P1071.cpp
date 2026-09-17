#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    bool seen[26] = {false};
    int cnt = 0;
    for (int i = 0; i < (int)s2.size(); i++)
    {
        if (!seen[s2[i] - 'A'])
        {
            seen[s2[i] - 'A'] = true;
            cnt++;
        }
    }
    if (cnt < 26)
    {
        cout << "Failed\n";
        return;
    }

    char plain_to_cipher[26];
    char cipher_to_plain[26];
    for (int i = 0; i < 26; i++)
    {
        plain_to_cipher[i] = -1;
        cipher_to_plain[i] = -1;
    }
    bool cipher_used[26] = {false};

    for (int i = 0; i < (int)s1.size(); i++)
    {
        int c = s1[i] - 'A';
        int p = s2[i] - 'A';

        if (plain_to_cipher[p] != -1 && plain_to_cipher[p] != c)
        {
            cout << "Failed\n";
            return;
        }
        if (cipher_used[c] && plain_to_cipher[p] != c)
        {
            cout << "Failed\n";
            return;
        }

        plain_to_cipher[p] = c;
        cipher_to_plain[c] = p;
        cipher_used[c] = true;
    }

    for (int i = 0; i < (int)s3.size(); i++)
    {
        cout << char(cipher_to_plain[s3[i] - 'A'] + 'A');
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}