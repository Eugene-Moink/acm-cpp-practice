#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int arr[3];
    for (int i = 0; i < 3;i++)
    {
        int num;
        cin >> num;
        arr[i] = num;
    }

    sort(arr, arr + 3);
    for (int i = 0; i < 3; i++)
    {
        cout << arr[i];
        if (i<2)
        {
            cout << "->";
        }
        
    }
    
}