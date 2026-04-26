#include <bits/stdc++.h>

using namespace std;

int main()
{
    string zi;
    getline(cin,zi);

    int cnt = 0;
    for (int i = 0; i < zi.size();i++)
    {
        if(zi[i]>='A'&&zi[i]<='Z')
        {
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}