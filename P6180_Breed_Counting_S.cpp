#include<bits/stdc++.h>
#define ensdl "\n"
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, Q;
    cin >> N >> Q;
    vector<long> prefix_1(N + 1,0);
    vector<long> prefix_2(N + 1,0);
    vector<long> prefix_3(N + 1,0);

    vector<long> cow_1(N + 1,0);
    vector<long> cow_2(N + 1,0);
    vector<long> cow_3(N + 1,0);

    for (int i = 1; i <= N;i++){
        int cow_number;
        cin >> cow_number;
        if(cow_number==1){
            cow_1[i]++;
        }
        if(cow_number==2){
            cow_2[i]++;
        }
        if(cow_number==3){
            cow_3[i]++;
        }
    }

    for (int i = 1; i <= N;i++)
    {
        prefix_1[i] = prefix_1[i - 1] + cow_1[i];
        prefix_2[i] = prefix_2[i - 1] + cow_2[i];
        prefix_3[i] = prefix_3[i - 1] + cow_3[i];
    }

    while(Q--){
        int l, r;
        cin >> l >> r;
        cout << prefix_1[r] - prefix_1[l - 1] << " "
             << prefix_2[r] - prefix_2[l - 1] << " "
             << prefix_3[r] - prefix_3[l - 1] << endl;
    }
}