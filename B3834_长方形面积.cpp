#include<bits/stdc++.h>
using namespace std;
int main()
{
    int A;
    cin >> A;
    int cnt = 0;
    for (int i = 1; i <= sqrt(A);i++)
    {
        if(A%i==0)
        {
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}