#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int find_first_ge(const vector<int>& arr, int target) 
{
    if (arr.empty()) return -1;
    
    int left = 0, right = arr.size() - 1;
    int result = -1;
    
    while (left <= right) 
    {
        int mid = (left + right) / 2;

        if (arr[mid] >= target) 
        {
            result = arr[mid]; 
            right = mid - 1;   
        } 

        else 
        {
            left = mid + 1;
        }
    }
    
    return result;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin >> n;

    vector<long long> people(n + 1, 0);
    vector<long long> prefix_people(n + 1, 0);
    for (int i = 1; i <= n;i++)
    {
        cin >> people[i];
        prefix_people[i] = prefix_people[i - 1] + people[i];
    }

    vector<vector<int>> pos(10); 
    
    for (int i = 0; i <= n; i++)
    {
        int remain = prefix_people[i] % 10;
        pos[remain].push_back(i);
    }

    vector<int> ans(n + 1, -1);

    for (int k = 1; k <= n; k++)
    {
        int target_remain = prefix_people[k - 1] % 10;
        vector<int>& vec = pos[target_remain];
        
        int j = find_first_ge(vec, k);
        
        if (j != -1 && j <= n)
        {
            ans[k] = j - k + 1;
        }
    }

    for (int k = 1; k <= n; k++)
    {
        cout << ans[k];
        if (k < n) cout << " ";
    }
    cout << endl;

    return 0;
}