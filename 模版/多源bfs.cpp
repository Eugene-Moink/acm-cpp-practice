#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9; // 初始距离设为一个足够大的数，用来表示“未被访问”

// 方向数组：根据题目是4连通还是8连通，选择调用
int dx4[4] = {1, -1, 0, 0};
int dy4[4] = {0, 0, 1, -1};

int dx8[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy8[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

/**
 * 多源 BFS 核心模板
 *
 * @param H            网格行数
 * @param W            网格列数
 * @param grid         网格字符数组
 * @param start_char   起点字符（例如 '#'，所有该字符的位置都会作为起点）
 * @param obstacle     障碍物字符（遇到该字符不扩散，若没有障碍物，保持默认 '\0' 即可）
 * @return             返回一个 H x W 的二维数组 dist，dist[i][j] 表示格子 (i,j) 到最近起点的距离
 */
vector<vector<int>> multi_source_bfs(int H, int W, const vector<string> &grid, char start_char, char obstacle = '\0')
{
    // 1. 初始化距离数组，全部设为 INF（表示未访问）
    vector<vector<int>> dist(H, vector<int>(W, INF));
    queue<pair<int, int>> q;

    // 2. 将所有起点入队，并设距离为 0
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            if (grid[i][j] == start_char)
            {
                dist[i][j] = 0;
                q.push(make_pair(i, j));
            }
        }
    }

    // 3. BFS 扩散（默认使用4邻域，即上下左右；如果需要8邻域，请将循环改成 k < 8，并换用 dx8/dy8）
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        int x = cur.first;
        int y = cur.second;

        for (int k = 0; k < 4; ++k)
        {
            int nx = x + dx4[k];
            int ny = y + dy4[k];

            // 越界检查
            if (nx < 0 || nx >= H || ny < 0 || ny >= W)
                continue;

            // 障碍物检查（只有指定了 obstacle 字符才会生效）
            if (obstacle != '\0' && grid[nx][ny] == obstacle)
                continue;

            // 已经访问过的格子跳过（通过判断距离是否还是 INF）
            if (dist[nx][ny] != INF)
                continue;

            // 更新距离并入队
            dist[nx][ny] = dist[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }

    // 4. 返回距离数组，供后续处理
    return dist;
}