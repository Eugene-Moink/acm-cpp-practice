#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int N,A,B;
    cin >> N >> A >> B;

    int total_h = A * N;
    int total_w = B * N;

    for (int r = 0; r < total_h;r++)
    {
        for (int c = 0; c < total_w;c++)
        {
            int cur_r = r / A;
            int cur_c = c / B;

            if((cur_c+cur_r)%2==0)
            {
                cout << '.';
            }
            else
            {
                cout << '#';
            }
        }
        cout << endl;
    }
}

int main()
{
    moink();
    return 0;
}