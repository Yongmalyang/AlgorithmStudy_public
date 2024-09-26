#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int n = friends.size();
    
    map<string, int> gift_dict;
    
    vector<vector<int>> gift_table(n, vector<int>(n, 0));
    
    vector<int> gift_score(n, 0);
    vector<int> total_gift(n, 0);
    
    for (int i = 0; i < n; ++i) {
        gift_dict[friends[i]] = i;
    }
    
    for(string gift : gifts) {
        string a, b;
        
        stringstream ss (gift);
        ss >> a >> b;
        
        gift_table[gift_dict[a]][gift_dict[b]]++;
        gift_score[gift_dict[a]]++;
        gift_score[gift_dict[b]]--;
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            if (gift_table[i][j] > gift_table[j][i]) {
                total_gift[i] += 1;
            } else if (gift_table[i][j] == gift_table[j][i]) {
                if (gift_score[i] > gift_score[j]) {
                    total_gift[i] += 1;
                }
            }
        }
    }
    
    int max_gift = total_gift[0];
    for (int i = 1; i < total_gift.size(); ++i) {
        if (total_gift[i] > max_gift) {
            max_gift = total_gift[i];
        }
    }
    return max_gift;
}