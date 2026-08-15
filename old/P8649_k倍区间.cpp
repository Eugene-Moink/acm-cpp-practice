#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N,K;
    cin >> N >> K;

    unordered_map<int, long long> mod_count;
    mod_count[0] = 1;

    vector<long long> number(N + 1, 0);
    vector<long long> prefix(N + 1, 0);
    long long cnt = 0;

    for (int i = 1; i <= N;i++){
        cin >> number[i];
        prefix[i] = prefix[i - 1] + number[i];
        int mod = prefix[i] % K;

        cnt += mod_count[mod];
        mod_count[mod]++;
        // cout << "prefix[i]:" << prefix[i] << endl;
    }

    // for (int i = 1; i <= N;i++){
    //     if(prefix[i]%K==0)
    //         cnt++;
    // }
    cout << cnt << endl;
    return 0;
}