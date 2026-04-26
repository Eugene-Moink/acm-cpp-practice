#include<iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n;i++)
    {
        long long number;
        cin >> number;
        sum += number;
    }

    cout << sum << endl;

    return 0;
}