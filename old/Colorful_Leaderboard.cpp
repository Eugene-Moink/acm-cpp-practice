#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int n;
    cin >> n;
    vector<bool> color(8, false); 
    int free = 0;                 

    for (int i = 0; i < n; ++i) 
    {
        int a;
        cin >> a;
        if (a >= 3200) 
        {
            free++;
        } 
        else 
        {
            int idx = a / 400;        
            if (idx > 7) idx = 7;     
            color[idx] = true;
        }
    }

    int base = 0;
    for (int i = 0; i < 8; ++i) 
    if (color[i]) base++;

    int minAns = (base == 0) ? 1 : base; 
    int maxAns = base + free;            

    cout << minAns << " " << maxAns << endl;
}

int main()
{
    moink();
    return 0;
}