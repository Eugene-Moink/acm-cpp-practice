#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    int good_number;
    cin >> good_number;
    vector<string> str(n);

    for (int i = 0; i < n;i++)
    {
        cin >> str[i];
    }

    int pair_number = 0;
    for (int i = 0; i < n; i++) 
    {
        for (int j = i + 1; j < n && j <= i + good_number; j++)
        {
            if (str[i].length() == str[j].length()) 
            {
                pair_number++;
            }
        }
    }

    cout << pair_number << endl;
    return 0;
}