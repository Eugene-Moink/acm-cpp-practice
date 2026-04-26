#include<iostream>
#include<set>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    set<int> numbers;
    for (int i = 0; i < n;i++)
    {
        int num;
        cin >> num;
        numbers.insert(num);
    }

    if(numbers.size()<k)
    {
        cout << "NO RESULT" << endl;
        return 0;
    }

    set<int>::iterator it= numbers.begin();
    for (int m = 0; m < k-1;m++)
    {
        it++;
    }

    cout << *it << endl;
    
    return 0;
}

