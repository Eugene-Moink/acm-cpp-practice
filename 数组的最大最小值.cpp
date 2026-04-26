#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> numbers;
    for (int i = 0; i < n;i++)
    {
        long long number;
        cin >> number;
        numbers.push_back(number);
    }

    long long max_num = numbers[0];
    long long min_num = numbers[0];

    for (int i = 0; i < n;i++)
        {
            max_num = max(max_num, numbers[i]);
            min_num = min(min_num, numbers[i]);
        }

        
    cout << max_num << " " << min_num << endl;
    return 0;
}