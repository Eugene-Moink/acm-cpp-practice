#include <bits/stdc++.h>
using namespace std;

int n, r;
vector<int> cur;  // 当前选择的组合（严格递增）

void dfs(int start) {
    // 终止：选满 r 个数
    if ((int)cur.size() == r) {
        for (int v : cur) cout << setw(3) << v;
        cout << '\n';
        return;
    }

    // 剪枝：剩余还需要选 need 个数
    int need = r - (int)cur.size();
    for (int x = start; x <= n - need + 1; x++) {
        cur.push_back(x);   // 选择 x
        dfs(x + 1);         // 下一位只能从 x+1 开始（保证递增不重复）
        cur.pop_back();     // 回溯撤销，尝试下一个 x
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> r;
    dfs(1);                 // 第一位从 1 开始选
    return 0;
}