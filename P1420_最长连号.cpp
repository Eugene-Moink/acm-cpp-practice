#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    int cnt = 1;
    int max_num = 1;
    int first_number;
    cin >> first_number;
    int prev_number = first_number;

    for (int i = 2; i <= n; i++) {
        int number;
        cin >> number;

        if (number == prev_number + 1) {
            cnt++;
        } else {
            max_num = max(max_num, cnt);
            cnt = 1;
        }

        prev_number = number;
    }

    max_num = max(max_num, cnt);

    cout << max_num << endl;
    return 0;
}