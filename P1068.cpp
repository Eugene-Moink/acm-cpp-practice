#include <bits/stdc++.h>
using namespace std;

struct Student
{
    int id, score;
    bool operator<(const Student &other) const
    {
        if (score != other.score)
            return score > other.score; // 成绩降序
        return id < other.id;           // 同分报名号升序
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Student> stu(n);
    for (int i = 0; i < n; i++)
    {
        cin >> stu[i].id >> stu[i].score;
    }

    sort(stu.begin(), stu.end());

    int k = m * 3 / 2;
    int cutoff = stu[k - 1].score;

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (stu[i].score >= cutoff)
            cnt++;
        else
            break;
    }

    cout << cutoff << " " << cnt << '\n';
    for (int i = 0; i < cnt; i++)
    {
        cout << stu[i].id << " " << stu[i].score << '\n';
    }

    return 0;
}