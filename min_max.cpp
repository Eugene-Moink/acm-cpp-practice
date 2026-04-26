#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    int min_num = min(a, b);
    int max_num = max(a, b);

    cout << max_num << " " << min_num << endl;

    return 0;
}