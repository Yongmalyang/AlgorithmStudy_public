#include <iostream>
#include <vector>
using namespace std; 

// 상하좌우
vector<int> x = {0, 0, -1, 1};
vector<int> y = {-1, 1, 0, 0};

bool is_in_board(int x, int y, int m, int n){
    return x>=0 && y>=0 && x<m && y<n;
}

bool ripe_tomatos(vector<vector<int>>& arr, int m, int n){
    int newly_ripe = 0;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            // 상하좌우
            for(int k=0; k<4; k++){
                if(is_in_board(i+x[k], j+y[k], m, n)){
                    if(arr[i+x[k]][j+y[k]]==0){
                        newly_ripe++;
                        arr[i+x[k]][j+y[k]] = 1;
                    }
                }
                
            }
        }
    }

    if(newly_ripe > 0) return true;
    else return false;
}

bool check_if_unfinished(vector<vector<int>> arr, int m, int n){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j]==0) return true;
        }
    }
    return false;
}

int main(){
    int m, n;
    cin >> m >> n;
    
    vector<vector<int>> arr(m, vector<int>(n, 0));

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    bool keep_checking = true;
    int answer = 0;

    while(keep_checking){
        keep_checking = ripe_tomatos(arr, m, n);
        answer++;
    }
    
    if(check_if_unfinished(arr, m, n)) cout << -1;
    else cout << answer;

    return 0;
}