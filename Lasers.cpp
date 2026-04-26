#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        long long x, y;
        cin >> n >> m >> x >> y;

        vector<long long> a(n), b(m);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < m; ++i) cin >> b[i];

        vector<long long> h_lines = {0, y};
        h_lines.insert(h_lines.end(), a.begin(), a.end());
        sort(h_lines.begin(), h_lines.end());

        vector<long long> v_lines = {0, x};
        v_lines.insert(v_lines.end(), b.begin(), b.end());
        sort(v_lines.begin(), v_lines.end());

        int start_r = lower_bound(h_lines.begin(), h_lines.end(), 0LL) - h_lines.begin() - 1;
        int start_c = lower_bound(v_lines.begin(), v_lines.end(), 0LL) - v_lines.begin() - 1;
        int end_r = lower_bound(h_lines.begin(), h_lines.end(), y) - h_lines.begin() - 1;
        int end_c = lower_bound(v_lines.begin(), v_lines.end(), x) - v_lines.begin() - 1;

        queue<tuple<int, int, int>> q;
        vector<vector<bool>> visited(h_lines.size() - 1, vector<bool>(v_lines.size() - 1, false));

        q.push(make_tuple(start_r, start_c, 0));
        visited[start_r][start_c] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            int r, c, dist;
            tie(r, c, dist) = q.front(); q.pop();

            if (r == end_r && c == end_c) {
                cout << dist << endl;
                break;
            }

            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < (int)h_lines.size() - 1 && nc >= 0 && nc < (int)v_lines.size() - 1 && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    q.push(make_tuple(nr, nc, dist + 1));
                }
            }
        }
    }
    return 0;
}