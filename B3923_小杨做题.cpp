#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    long long a, b, m, N;
    cin >> a >> b >> m >> N;

    long long result = 0;
   
    if(a >= m) 
    {
        cout << 0 << endl;
        return 0;
    } 
    else 
    {
        result += a;
        if(N == 1) 
        {
            cout << result << endl;
            return 0;
        }
    }
    
    if(b >= m) 
    {
        cout << result << endl;  // 只包含第一天的题目数
        return 0;
    } 
    else 
    {
        result += b;
        if(N == 2) 
        {
            cout << result << endl;
            return 0;
        }
    }

    vector<long long> do_number(N + 2);
    do_number[1] = a;
    do_number[2] = b;
    do_number[3] = do_number[2] + do_number[1];


    for (int i = 3; i <= N;i++)
    {
        result += do_number[i];
      
        if(i>=2 && i+1<=N)
        {
            do_number[i + 1] = do_number[i] + do_number[i - 1];
        }

        if(do_number[i]>=m)
        {
            break;
        }
    }
    cout << result << endl;
    return 0;
}