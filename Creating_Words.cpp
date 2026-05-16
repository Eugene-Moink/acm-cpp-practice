#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        string str1, str2;
        cin >> str1 >> str2;
        for (int i = 0; i < str1.size();i++)
        {
            if(i==0)
            {
                cout << str2[i];
            }

            else{
                cout << str1[i];
            }
        }

        cout << " ";

         for (int i = 0; i < str2.size();i++)
        {
            if(i==0)
            {
                cout << str1[i];
            }

            else{
                cout << str2[i];
            }
        }

        cout << endl;
    }
    return 0;
}