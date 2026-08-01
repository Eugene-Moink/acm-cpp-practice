#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int n;
    cin >> n;
    vector<int> part;

    int base = 1;
    while (n>0)
    {
        int dight = n % 10;
        if(dight!=0)
        {
            part.push_back(dight * base);
        }
        n /= 10;
        base *= 10;
    }

    cout << part.size() << endl;
    for (auto x : part)
    {
        cout << x << " ";
    }

    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        moink();
    }
    return 0;
}
