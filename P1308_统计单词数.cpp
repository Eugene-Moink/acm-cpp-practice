#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    string word;
    cin >> word;

    cin.ignore();
    string text;
    getline(cin, text);

    transform(word.begin(), word.end(), word.begin(), ::tolower);
    transform(text.begin(), text.end(), text.begin(), ::tolower);

    ll cnt = 0;
    ll first_pos = -1;

    size_t pos = 0;

    while((pos=text.find(word,pos))!=string::npos)
    {
        bool left_ok = (pos == 0 || text[pos - 1] == ' ');
        ll len = word.size();
        bool right_ok = ((pos + len == (ll)text.size()) || text[pos + len] == ' ');

        if (left_ok && right_ok)
        {
            cnt++;
            if(first_pos==-1)
                first_pos = pos;
        }
        pos = pos + word.size();
    }

    if(cnt==0)
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << cnt << " " << first_pos << endl;
    }
}

int main()
{
    moink();
    return 0;
}