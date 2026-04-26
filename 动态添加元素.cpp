#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> v;
    while (true)
    {
        int number;
        cin >> number;

        if (number==-1)
        {
            break;
        }

        v.push_back(number);
    }

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];

        if (i!=v.size()-1)
        {
            cout << " ";
        }

    }
    
    
        cout << endl;

        return 0;
}