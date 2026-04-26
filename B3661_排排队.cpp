#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> odds;
    vector<int> evens;

    for (int i = 0; i < n;i++)
    {
        int number;
        cin >> number;

        if (number%2==1)
        {
            odds.push_back(number);
        }
        else
        {
            evens.push_back(number);
        }
        
    }

    for (int i = 0; i < odds.size(); ++i)
    {
        cout << odds[i];
        if (i!=odds.size()-1)
        {
            cout << " ";
        } 
    }

    cout << endl;

    
    for (int i = 0; i < evens.size(); ++i)
    {
        cout << evens[i];
        if (i!=evens.size()-1)
        {
            cout << " ";
        } 
    }

    cout << endl;

    return 0;
}