#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int T, M, N, K;
int field[50][50];
bool visited[50][50];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[y][x] = true;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;

            if (field[ny][nx] == 0 || visited[ny][nx]) continue;

            visited[ny][nx] = true;
            q.push({nx, ny});
        }
    }
}


int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);            

    cin >> T;

    while (T--) {
        cin >> M >> N >> K;

        memset(field, 0, sizeof(field));
        memset(visited, false, sizeof(visited));

        for (int i = 0; i < K; i++) {
            int x, y;
            cin >> x >> y;
            field[y][x] = 1; 
        }

        int wormCount = 0;

        for (int i = 0; i < N; i++) {       
            for (int j = 0; j < M; j++) {  
                if (field[i][j] == 1 && !visited[i][j]) {
                    bfs(j, i); 
                    wormCount++;
                }
            }
        }

        cout << wormCount << '\n';
    }

    return 0;
}
