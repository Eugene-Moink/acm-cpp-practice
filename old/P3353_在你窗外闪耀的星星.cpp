#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main(){
    int N, W;
    cin >> N >> W;
    vector<pair<long long, long long>> stars;

   for (int i = 0; i < N;i++){
        int x, b;
        cin >> x >> b;
        stars.push_back({x, b});
    }

    sort(stars.begin(), stars.end());

    // for (int i = 0; i < N;i++){
    //     cout << stars[i].first<<":"<<stars[i].second<<endl;
    // }

    long long max_sum=0;
    long long current_sum = 0;
    int left = 0;

    for (int right = 0; right < N; right++) {
        current_sum += stars[right].second;

        while (stars[right].first>stars[left].first+W)
        {
            current_sum -= stars[left].second;
            left++;
        }

        max_sum = max(max_sum, current_sum);
    }

    cout << max_sum << endl;
    return 0;
}