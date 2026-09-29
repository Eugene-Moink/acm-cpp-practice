#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Student
{
    int id;
    int ch, ma, en;
    int total;

    bool operator<(const Student &other) const
    {
        if (total != other.total)
            return total > other.total;
        if (ch != other.ch)
            return ch > other.ch;
        return id < other.id;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<Student> stu(n);
    for (int i = 0; i < n; i++)
    {
        stu[i].id = i + 1;
        cin >> stu[i].ch >> stu[i].ma >> stu[i].en;
        stu[i].total = stu[i].ch + stu[i].ma + stu[i].en;
    }

    sort(stu.begin(), stu.end());
    for (int i = 0; i < 5; i++)
    {
        cout << stu[i].id << " " << stu[i].total << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}