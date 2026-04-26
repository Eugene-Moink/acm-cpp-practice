#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string text;
    getline(cin, text);

    //请在此处查找 "LOVE"
    size_t pos = text.find("LOVE");
    if (pos != string::npos) 
    {
        cout << "I love you." << endl;
    } else {
        cout << "I don't know." << endl;
    }

    return 0;
}