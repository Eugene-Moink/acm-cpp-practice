#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    string s;
    cin >> s;
    string target = "keyence";
    int n = s.size();

    int left = 0;
    while(left < n && left < 7 && s[left] == target[left])
    {
        left++;
    }
    int right = 0;
    while(right < n && right < 7 && s[n - 1 - right] == target[6 - right])
    {
        right++;
    }
    if (left + right >= 7)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}

int main()
{
    moink();
    return 0;
}