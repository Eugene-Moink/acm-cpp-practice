#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<long long> id(N + 1, 0);
    vector<long long> prefix(N + 1, 0);

    for (int i = 1; i <= N;i++){
        cin >> id[i];
        prefix[i] = prefix[i - 1] + id[i];
    }

    vector<int> first_occurrence(7, -1);
    first_occurrence[0] = 0;
    int max_length = 0;

    for (int i = 1; i <= N;i++){
        int r = prefix[i] % 7;
        if(first_occurrence[r]==-1)first_occurrence[r] = i;
        else{
            int current_length = i - first_occurrence[r];
            max_length = max(max_length, current_length);
        }
    }

    cout << max_length << endl;
    return 0;
}