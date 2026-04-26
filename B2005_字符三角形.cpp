#include<iostream>
using namespace std;

int main()
{
    char c;
    cin >> c;
    int height = 3;

    for (int i = 1; i <= 3; i++)
    {
        for (int j = 0; j < height - i; j++)
        {
            cout << " ";
        }

         for (int k = 0; k < 2*i-1; k++)
        {
            cout << c;
        }

        cout << endl;
    }

   
    return 0;
}