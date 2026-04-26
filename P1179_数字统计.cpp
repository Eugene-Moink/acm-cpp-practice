#include <string>
#include<iostream>
using namespace std;


int countTwosInNumber(int num) 
{
    string s = to_string(num);

    int count = 0;

    for (int i = 0; i < s.length(); i++) 
    { 
        if (s[i]=='2') 
        {
            count++;
        }
    }

    return count;
}

int main()
{
    int L, R;
    cin >> L >> R;

    int total = 0;

    for (int i = L; i <= R;i++)
    {
        total += countTwosInNumber(i);
    }

    cout << total << endl;

    return 0;
}