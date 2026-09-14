const int INF = 1e9;

int dx4[4] = {1, -1, 0, 0};
int dy4[4] = {0, 0, 1, -1};

int dx8[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy8[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

vector<vector<int>> multi_source_bfs(int H, int W, const vector<string> &grid, char start_char, char obstacle = '\0')
{
    vector<vector<int>> dist(H, vector<int>(W, INF));
    queue<pair<int, int>> q;

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

            if (nx < 0 || nx >= H || ny < 0 || ny >= W)
                continue;

            if (obstacle != '\0' && grid[nx][ny] == obstacle)
                continue;

            if (dist[nx][ny] != INF)
                continue;

            dist[nx][ny] = dist[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }

    return dist;
}

void solve()
{
    int H, W;
    if (!(cin >> H >> W))
        return;

    vector<string> grid(H);
    for (int i = 0; i < H; ++i)
        cin >> grid[i];

    char start_char, obstacle;
    cin >> start_char >> obstacle;

    vector<vector<int>> dist = multi_source_bfs(H, W, grid, start_char, obstacle);

    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            if (dist[i][j] == INF)
                cout << "-1";
            else
                cout << dist[i][j];
            if (j + 1 < W)
                cout << " ";
        }
        cout << "\n";
    }
}