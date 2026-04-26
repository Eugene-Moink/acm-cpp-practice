#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int min_num;
    int n;
    cin >> n;
    cin >> min_num;
    for (int i = 1; i < n;i++)
    {
        int num;
        cin >> num;
        min_num = min(min_num, num);
    }

    cout << min_num << endl;
    return 0;
}
