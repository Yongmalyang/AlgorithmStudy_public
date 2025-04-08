#include <iostream>
#include <vector>
#include <queue>

using namespace std; 

int n;
char grid[100][100];
bool visited[100][100];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void bfs(char color, bool is_colorblind, int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
            if(!visited[nx][ny] && !is_colorblind && grid[nx][ny] == color){
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
            else if(!visited[nx][ny] && is_colorblind){
                if(color=='B' && grid[nx][ny]=='B'){
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
                else if((color=='G' || color=='R') && (grid[nx][ny]=='G' || grid[nx][ny]=='R')){
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> grid[i][j];
        }
    }

    int non_colorblind = 0;
    int colorblind = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                bfs(grid[i][j], false, i, j);
                non_colorblind++;
            }
        }
    }

    fill(&visited[0][0], &visited[0][0] + 100*100, false);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                bfs(grid[i][j], true, i, j);
                colorblind++;
            }
        }
    }

    cout << non_colorblind << " " << colorblind << endl;
    return 0;
}