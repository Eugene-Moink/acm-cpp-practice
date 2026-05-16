#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;

    for (int hl = 1; hl <= H;hl++)
    {
        for (int wl = 1; wl <= W;wl++)
        {
            if((hl==1||hl==H)&&(wl==1||wl==W))
            {
                cout << H - 3;
            }
            else if((hl==1||hl==H)&&(wl>1&&wl<W))
            {
                cout << H - 2;
            }
            else if((hl>1&&hl<H)&&(wl>1&&wl<W))
            {
                cout << H - 1;
            }
            else if((hl>1&&hl<H)&&(wl==1||wl==W))
            {
                cout << H - 2;
            }
            if(wl<W)
            {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}