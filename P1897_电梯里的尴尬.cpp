#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

int main()
{
    int n;
    long long sum = 0;
    cin >> n;
    vector<int> floor;
    set<int> differ_floor;

    for (int i = 0; i < n;i++)
    {
        int floor_num;
        cin >> floor_num;
        floor.push_back(floor_num);
    }

    int max_floor = -1;
    for (int i = 0; i < n;i++)
    {
        differ_floor.insert(floor[i]);
        max_floor = max(max_floor, floor[i]);
    }



    long long up_down_time = 10 * max_floor;
    long long people_down = n;
    long long open_time = (long long)differ_floor.size() * 5;

    sum = up_down_time + people_down + open_time;

    cout << sum << endl;
    return 0;

}