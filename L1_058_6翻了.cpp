#include<bits/stdc++.h>
using namespace std;

int main()
{
    string sentence;
    getline(cin, sentence);

    int n = sentence.length();
    int i = 0;
    //cout << n;

    while(i<n)
    {
        if(sentence[i]=='6')
        {
            int count_6 = 0;
            int j = i;

            while(j<n&&sentence[j]=='6')
            {
                count_6++;
                j++;
            }

             if(count_6>9)
                {
                    cout << "27";
                }

                else if(count_6>3)
                {
                    cout << "9";
                }

                else
                {
                    for (int k = 0; k < count_6;k++)
                    {
                        cout << "6";
                    }
                }

            i = j;

        }

        else
        {
            cout << sentence[i];
            i++;
        }

    }

    return 0;
}