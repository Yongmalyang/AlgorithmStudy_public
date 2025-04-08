#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int grid[100][100];
int dist[100][100];
bool visited[100][100];

void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});

    visited[x][y] = true;
    dist[x][y] = 1;

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];    
            
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (grid[nx][ny] == 0 || visited[nx][ny]) continue;

            visited[nx][ny] = true;
            dist[nx][ny] = dist[cx][cy] + 1;
            q.push({nx, ny});
        }
    }
}

int main(){
    cin >> n >> m;
    string line;
    for(int i = 0; i < n; i++){
        cin >> line;
        for(int j = 0; j < m; j++){
            grid[i][j] = line[j] - '0';
        }
    }

    bfs(0, 0);

    cout << dist[n-1][m-1] << endl;
    return 0;
}
