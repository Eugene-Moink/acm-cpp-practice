#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int first_numer;
    cin >> first_numer;

    vector<int> result;
    result.push_back(first_numer);

    int query;
    cin >> query;

    while(query)
    {
        int num1, num2;
        cin >> num1 >> num2;
        result.push_back(num1);
        result.push_back(num2);

        sort(result.begin(), result.end());
        cout << result[result.size() / 2] << endl;
    }
}