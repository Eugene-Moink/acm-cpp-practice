#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    int T;
    cin >> T;
    while(T--){
        long long n;
        cin >> n;
        vector<long long> number(n + 1, 0);
        vector<long long> prefix(n + 1, 0);
        long long sum = 0;
        for (int i = 1; i <= n;i++){
            cin >> number[i];
            sum += number[i];
        }

        for (int i = 1; i <= n - 1;i++){
            prefix[i] = prefix[i - 1] + number[i];
        }
            if (sum % 2 != 0)
            {
                cout << "No" << endl;
            }
            else{
                bool temp = 0;
                for (int i = 1; i < n ;i++)
                {
                    if(prefix[i]==sum/2)
                    {
                        temp = 1;
                    }
                }
                if(temp==0)
                    cout << "No" << endl;
                else
                    cout << "Yes" << endl;
        }
    }
    return 0;
}