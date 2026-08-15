#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int m;
    cin >> m;
    vector<int> score_people(m + 1,0);
    vector<int> prefix_people(m + 1,0);

    for (int i = 1; i <= m;i++)
    {
        cin >> score_people[i];
        prefix_people[i] = prefix_people[i - 1] + score_people[i];
    }

    int x, y;
    cin >> x >> y;

    long long total = prefix_people[m];

    int ans = 0;
    for (int k = 1; k <= m; k++) {
        long long n1 = total - prefix_people[k - 1];
        long long n2 = prefix_people[k - 1];

        if (x <= n1 && n1 <= y && x <= n2 && n2 <= y) {
            ans = k;
            break; 
        }
    }

    cout << ans << endl;

    return 0;
}