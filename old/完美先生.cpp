#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<pair<int, string>> book;
        int best11 = INT_MAX, best10 = INT_MAX, best01 = INT_MAX;
        for (int i = 0; i < n;i++)
        {
            int num;
            string str;
            cin >> num >> str;
            book.push_back({num, str});
        }

        for (int i = 0; i < n;i++)
        {
            if(book[i].second=="11")
            {
                best11 = min(best11, book[i].first);
            }

            if(book[i].second=="10")
            {
                best10 = min(best10, book[i].first);
            }

            if(book[i].second=="01")
            {
                best01 = min(best01, book[i].first);
            }
        }

        int ans = INT_MAX;

        if (best11 != INT_MAX) 
            ans = min(ans, best11);

        if (best10 != INT_MAX && best01 != INT_MAX) 
            ans = min(ans, best10 + best01);

        if (ans == INT_MAX) 
            cout << -1 << endl;

        else    
            cout << ans << endl;
    }
    return 0;
}