#include <iostream>
#include <vector>
#include <queue>
using namespace std; 

int n, m;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int board[500][500];
bool visited[500][500];

int bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    int area = 1;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = cx + dx[d];
            int ny = cy + dy[d];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (!visited[nx][ny] && board[nx][ny] == 1) {
                visited[nx][ny] = true;
                q.push({nx, ny});
                area++;
            }
        }
    }
    return area;
}

int main(){

    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
        }
    }

    int pictureCount = 0;
    int maxArea = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 1 && !visited[i][j]) {
                int area = bfs(i, j);
                pictureCount++;
                if (area > maxArea) maxArea = area;
            }
        }
    }

    cout << pictureCount << '\n' << maxArea << '\n';
    return 0;

}