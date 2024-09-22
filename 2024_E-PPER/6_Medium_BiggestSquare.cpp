/*
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int CheckBiggestSquareFromOrigin(vector<vector<int>> b, int x, int y){
    int length = 0;
    bool check = true;
        
    while(check){
        length++;
        if(x+length>=b.size() || y+length>=b[0].size()) break;
        for(int i=x; i<x+length; i++){
            if(b[i][y+length]!=1) check = false;
        }
        for(int i=y; i<y+length; i++){
            if(b[x+length][i]!=1) check = false;
        }
    }
    
    return length * length;
}

void CheckOffVisited(vector<vector<int>> &checked, int x, int y, int len){
    for(int i=x; i<x+len; i++){
        for(int j=y; j<y+len; j++){
            if(i<checked.size() && j<checked.size()){
                checked[i][j] = -1;
            }
        }
    }
}

int solution(vector<vector<int>> board)
{
    int answer = 0;
    
    int n = board.size();
    vector<int> tmp(n, 1);
    vector<vector<int>> checked(n, tmp);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(checked[i][j]!=-1){
                int size = CheckBiggestSquareFromOrigin(board, i, j);
                if(size>answer){
                    answer = size;
                    CheckOffVisited(checked, i, j, sqrt(size));
                }
            }
        }
    }

    return answer;
}

 */