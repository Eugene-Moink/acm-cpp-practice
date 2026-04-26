#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        stack<unsigned long long> st;

        for (int i = 0; i < n;i++)
        {
            string op;
            cin >> op;

            if(op == "push")
            {
                unsigned long long x;
                cin >> x;
                st.push(x);
            }

            else if(op == "pop")
            {
                if(st.empty())
                {
                    cout << "Empty" << endl;
                }
                else
                {
                    st.pop();
                }
            }

            else if(op == "query")
            {
               if(st.empty())
                {
                    cout << "Anguei!" << endl;
                }
                else
                {
                    cout << st.top() << endl;
                } 
            }

            else if(op == "size")
            {
                cout << st.size() << endl;
            }
        }
    }

    return 0;
}