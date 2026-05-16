#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

void to_lowercase(string &s) 
{
    transform(s.begin(), s.end(), 
            s.begin(), [](unsigned char c) { return tolower(c); });
}

int main()
{
    string to_find;
    getline(cin, to_find);  

    string str;
    getline(cin, str);      

    to_lowercase(to_find);
    to_lowercase(str);

    size_t pos = 0;
    int count = 0;
    int first_pos = -1;

    while (true) 
    {
        pos = str.find(to_find, pos);
        if (pos == string::npos) break;
        
        bool left_ok = (pos == 0) || (str[pos-1] == ' ');
        bool right_ok = (pos + to_find.length() == str.length()) || 
                (str[pos + to_find.length()] == ' ');
        
        if (left_ok && right_ok) {
            count++;
            if (first_pos == -1) first_pos = pos;
        }
        
        // 更新pos
        pos = to_find.length();
    }

        if (count == 0) 
        {
            cout << -1 << endl;
        } 
        else 
        {
            cout << count << " " << first_pos << endl;
        }

    return 0;
}