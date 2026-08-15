#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    ll result = 0;
    int n = s.length();
    ll current_number = 0;
    int sign = 1;

    for (int i = 0; i < n; ++i) {
        char c = s[i];
        if (isdigit(c)) {
            current_number = current_number * 10 + (c - '0');
        } else { 
            result += sign * current_number;
            sign = (c == '+') ? 1 : -1;
            current_number = 0;
        }
    }

    result += sign * current_number;

    cout << result << endl;

    return 0;
}