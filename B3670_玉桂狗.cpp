#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    long long R;
    cin >> n >> R;

    long long max_cuteness = -1;

    for (int i = 0; i < n; i++)
    {
        long long k, p;
        cin >> k >> p;

        if (p<=R)
        {
            max_cuteness = max(max_cuteness, k);
        }
        
    }

    cout << max_cuteness << endl;

    return 0;
}