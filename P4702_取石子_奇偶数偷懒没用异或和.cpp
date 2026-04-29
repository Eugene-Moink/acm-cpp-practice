#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int main(){
    int n;
    cin >> n;
    long long sum = 0;
    vector<long long> st(n+1);
    for (int i = 1; i <= n;i++){
        cin >> st[i];
        sum += st[i] % 2;
    }

    if(sum%2!=0){
        cout << "Alice" << endl;
    }
    else{
        cout << "Bob" << endl;
    }
    return 0;
}

