#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int main(){
    int n;
    cin >> n;
    long long sum = 0;
    long long sum_sum = 0;
    while(n--){
        long long number;
        cin >> number;
        sum += number;
        sum_sum += number * number;
    }

    long long result = (sum * sum - sum_sum) / 2;
    cout << result << endl;
    return 0;
}