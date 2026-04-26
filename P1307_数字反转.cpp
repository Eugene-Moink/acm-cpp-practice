#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    int number;
    cin >> number;
    int sign = 1;
    if (number<0)
    {
        number *= -1;
        sign = -1;
    }
    
    string number_new = to_string(number);

    reverse(number_new.begin(), number_new.end());

    while(number_new.length()>1&&number_new[0]=='0')
    {
        number_new.erase(0, 1);
    }

    int final_number = stoi(number_new) * sign;

    cout << final_number;

    cout << endl;
    return 0;
}