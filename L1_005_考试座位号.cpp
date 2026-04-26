#include<bits/stdc++.h>
using namespace std;

int main()
{
    struct StudentInfo 
    {
        std::string exam_id; 
        int test_seat;      
    };

    map<int, StudentInfo> seat_map;

    int n;
    cin >> n;

    for (int i = 0; i < n;i++)
    {
        string id;
        int trial_seat, test_seat;
        cin >> id >> trial_seat >> test_seat;
        seat_map[trial_seat] = {id, test_seat};
    }

    int M;
    cin >> M;

    for (int j = 0; j < M;j++)
    {
        int query_seat;
        cin >> query_seat;

        StudentInfo info = seat_map[query_seat];
        cout << info.exam_id << " " << info.test_seat << endl;
    }

    return 0;
}