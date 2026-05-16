#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int cnt = 0;
        string str;
        cin >> str;
        char temp = str[0];
        for (int i = 0; i < str.size();i++)
        {
            if(str[i]==temp)
            {
                cnt++;
            }
        }
        if(cnt==str.size())
        {
            cout << "NO" << endl;
        }

        else 
        {
            cout << "YES" << endl;
            string r = str;
            for(int i = 0; i < r.size(); i++) 
            {
                for(int j = i + 1; j < r.size(); j++) 
                {
                    if(r[i] != r[j]) 
                    {
                        swap(r[i], r[j]);
                        break;
                    }
                }
                if(r != str) break;
            }
            cout << r << endl;
        }
    }
    return 0;
}