#include<bits/stdc++.h>
using namespace std;

int main()
{
    int k, L, R;
    cin >> k >> L >> R;

    int sum = 0;
    for (int i = L; i <= R;i++)
    {
        if(i%k==0||i%10==k)
        {
            sum += i;
        }
    }

    cout << sum << endl;
    return 0;
}