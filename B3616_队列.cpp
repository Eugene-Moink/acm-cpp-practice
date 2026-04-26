#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    queue<long long> qu;

    for (int i = 0; i < n;i++)
    {
        int op;
        cin >> op;

        if(op == 1)
        {
            int x;
            cin >> x;
            qu.push(x);
        }
        else if(op == 2)
        {
            if(qu.empty())
            {
                cout << "ERR_CANNOT_POP" << endl;
            }
            else
            {
                qu.pop();
            }
        }
        else if(op == 3)
        {
            if(qu.empty())
            {
                cout << "ERR_CANNOT_QUERY" << endl;
            }
            else
            {
                cout << qu.front() << endl;
            }
        }
        else if(op == 4)
        {
            cout << qu.size() << endl;
        }
    }
    return 0;
}