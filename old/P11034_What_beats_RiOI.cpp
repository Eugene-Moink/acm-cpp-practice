#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

bool find_word(const string &s)
{
    for (size_t i = 0; i + 3 < s.size();++i)
    {
        if ((tolower(static_cast<unsigned char>(s[i]))   == 'r' &&
            tolower(static_cast<unsigned char>(s[i+1])) == 'i' &&
            tolower(static_cast<unsigned char>(s[i+2])) == 'o' &&
            tolower(static_cast<unsigned char>(s[i+3])) == 'i'))
            {
                return true;
            }
    }
    return false;
}

int main()
{
    string s;
    cin >> s;
    string t;
    cin >> t;

    bool ans_s = find_word(s);
    bool ans_t = find_word(t);

    if(ans_s&&ans_t)
    {
        cout << "Either is ok!" << endl;
    }

    else if(ans_s||ans_t)
    {
        if(ans_s)
        {
            cout << s << " for sure!" << endl;
        }

        if(ans_t)
        {
            cout << t << " for sure!" << endl;
        }
    }

    else
    {
        cout << "Try again!" << endl;
    }

    return 0;
}