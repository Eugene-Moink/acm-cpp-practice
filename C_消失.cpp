#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    map<long long, long long> cnt;
    long long sum = 0;

    for (int i = 0;i < N; i++){

        long long num;
        cin >> num;
        sum += num;
        cnt[num]++;
    }

    for (int op = 0; op < K; op++)
    {
        long long max_freq = 0;
        long long target_val = 0;
        
        for (auto& p : cnt) {
            if (p.second > max_freq) {
                max_freq = p.second;
                target_val = p.first;
            }
        }

        sum -= target_val * max_freq;
        cnt.erase(target_val);
    }

    cout << sum << endl;
    return 0;
}

    //     for (int i = 1; i <= N;i++){
    //     int number;
    //     cin >> number;
    //     sum += number;
    //     cnt[number]++;
    // }

    // while(K--){
    //     long long max_cnt=0;
    //     long long temp = 0;
    //     for (int i = 0; i < 10;i++){
    //         if(max_cnt<cnt[i])
    //         {
    //             max_cnt = cnt[i];
    //             temp++;
    //         }
    //     }
    //     sum -= temp * max_cnt;
    // }