#include<bits/stdc++.h>
using namespace std;
int sum(int number)
{
    int sum = 0;
    for (int i = 0; i <= number;i++)
    {
        sum += i;
    }

    return sum;
}

int main()
{
    int n;
    cin >> n;
    long long total = 0;
    for (int i = 0; i <= n;i++)
    {
        total += sum(i);
    }

    cout << total << endl;
    return 0;
}