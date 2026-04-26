#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;

    int max_len = 0;     
    int start_pos = 0;   

    for (int i = 2; i <= sqrt(n); ++i) {
        long long product = 1; 
        int current_len = 0;   

        for (int j = i; ; ++j) {
            if (product > n / j) {
                break;
            }
            
            product *= j;
            current_len++;

            if (n % product == 0) {
                if (current_len > max_len) {
                    max_len = current_len;
                    start_pos = i;
                }
            } else {
                break;
            }
        }
    }

    if (max_len == 0) {
        max_len = 1;
        start_pos = n;
    }

    cout << max_len << endl;
    for (int i = 0; i < max_len; ++i) {
        cout << start_pos + i;
        if (i < max_len - 1) {
            cout << "*";
        }
    }
    cout << endl;

    return 0;
}