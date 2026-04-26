#include<iostream>
#include<vector>
using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n + 1);

    long long sum = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum = sum + a[i];
    }

    long long change = -2 * a[k];

    long long sum_new = sum + change;

    cout << sum_new << endl;

    return 0;
}