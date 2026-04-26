#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> cute;
    for (int i = 0; i < n;i++)
    {
        int cute_num;
        cin >> cute_num;
        cute.push_back(cute_num);
    }

    for (int i = 0; i < n;i++)
    {
        int cnt = 0;
        for (int m = 0; m < i;m++)
        {
            if(cute[i]>cute[m])
            {
                cnt++;
            }
        }

        cout << cnt;

        if(i<n-1)
        {
            cout << " ";
        }
    }

    cout << endl;

    return 0;
}