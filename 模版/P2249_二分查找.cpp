#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
    {
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
    {
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}

ll lower_bound(vector<ll>& arr, ll target) 
{
    ll left = 0, right = arr.size();  
    while (left < right) 
    {
        ll mid = left + (right - left) / 2;
        if (arr[mid] < target)
        {
            left = mid + 1;
        } 
        else 
        {
            right = mid;  
        }
    }
        
        if (left < arr.size() && arr[left] == target) 
        {
            return left;  
        }
        return -1;
}

int main() 
{
    ll n=read(),m=read();
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    while(m--)
    {
        ll num;
        cin >> num;
        ll pos = lower_bound(arr, num);
        if (pos != -1) cout << pos + 1;
        else cout << "-1";
        if (m > 0) cout << " ";
    }
    
    return 0;
}