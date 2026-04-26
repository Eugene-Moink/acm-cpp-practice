#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++)
    {
        string player_1;
        string player_2;
        cin >> player_1 >> player_2;

        if(player_1 == player_2)
        {
            cout << "Tie" << endl;
        }

        else if((player_1=="Rock"&&player_2=="Scissors")||
        (player_1=="Scissors"&&player_2=="Paper")||
        (player_1=="Paper"&&player_2=="Rock"))
        {
            cout << "Player1" << endl;
        }

        
        else
        {
            cout << "Player2" << endl;
        }
    }
    return 0;
}