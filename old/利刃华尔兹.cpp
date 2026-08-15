#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
using ld = long double;

void moink()
{
    ld a, b, k;
    cin >> a >> b >> k;

    vector<int> skills = {0, 1, 2, 3}; 
    ld max_damage = 0;

    do {
        ld cur_b = b;
        ld total = 0;

        for(int id : skills)
        {
            if(id == 0)
            { 
                total += a + 0.9 * cur_b;
                cur_b *= 1.2;
            }
            else if(id == 1) 
            { 
                total += a + 2.0 * cur_b;
                cur_b *= 1.2;
                total += a + 2.0 * cur_b;
                cur_b *= 1.2;
            }
            else if(id == 2) 
            { 
                for(int i=0; i<4; i++) {
                    total += a + 5.0 * cur_b;
                    cur_b *= 1.2;
                }
            }
            else if(id == 3) 
            {
                total += 500;
                cur_b *= 1.2; 
            }
        }
        max_damage = max(max_damage, total);

    } while(next_permutation(skills.begin(), skills.end()));

    if (max_damage >= k) 
    {
        cout << "You have slain an enemy" << endl;
    } 
    else 
    {
        cout << "You have slain it" << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    moink();
    return 0;
}