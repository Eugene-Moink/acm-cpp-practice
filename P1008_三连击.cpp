#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    for (int a = 100; a <= 333;a++)
    {
        int number[10] = {0};

        int b = 2 * a;
        int c = 3 * a;

        string a_str = to_string(a);
        string b_str = to_string(b);
        string c_str = to_string(c);

        for (int i = 0; i < a_str.size();i++)
        {
            number[a_str[i] - '0']++;
            number[b_str[i] - '0']++;
            number[c_str[i] - '0']++;
        }

        bool temp = 0;
        for (int j = 1; j < 10;j++)
        {
            if(number[j]!=1)
            {
                temp = 1;
            }
        }

        if(temp==0)
        {
            cout << "   " << endl;
            cout << a << " " << b << " " << c << endl;
        }
    }

    return 0;
}