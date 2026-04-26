#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N;i++)
    {
        if(i%M==0)
        {continue;}
        cout << i << endl;
    }

    return 0;
}