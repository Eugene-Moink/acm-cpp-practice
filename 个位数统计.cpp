#include<iostream>
#include<string>
using namespace std;

int main()
{
    string n_str;
    cin >> n_str;

    int counts[10] = {0};
    int n = n_str.size();

    for (int i = 0; i < n;i++)
    {
        char now = n_str[i];

        int digit = now - '0';
        counts[digit]++;
    }

    for (int i = 0; i < 10; i++)
    {
        if (counts[i] > 0) 
        { 
            cout << i << ":" << counts[i] << endl;
        }
    }

    return 0;
}