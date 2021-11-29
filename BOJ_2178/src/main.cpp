#include <iostream>
#include <string>
#include <queue>
#include <map>

using namespace std;

vector<string> maze;
vector<vector<bool>> isVisited{};
vector<vector<int>> dist{};

const vector<int> dx{ -1, 0, 1, 0 };
const vector<int> dy{ 0, -1, 0, 1 };

void solve(int N, int M) {
    isVisited[0][0] = true;
    dist[0][0] = 1;

    queue<pair<int, int>> q{};
    q.push({0, 0});

    while (!q.empty()) {
        auto f = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            auto x = f.second + dx[i];
            auto y = f.first + dy[i];

            if (x < 0 || M <= x)
                continue;

            if (y < 0 || N <= y)
                continue;

            if ('1' == maze[y][x] && !isVisited[y][x]) {
                dist[y][x] = dist[f.first][f.second] + 1;
                q.push({y, x});
                isVisited[y][x] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    maze = vector<string>(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> maze[i];
    }

    isVisited = vector<vector<bool>>(N, vector<bool>(M, false));
    dist = vector<vector<int>>(N, vector<int>(M, 0));

    solve(N, M);
    cout << dist[N - 1][M - 1];

    return 0;
}