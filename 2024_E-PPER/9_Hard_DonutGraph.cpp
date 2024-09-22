#include <iostream>
#include <vector>

using namespace std;

const int MAX_VERTEX = 1000001; // 10^6 + 1

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4, 0); // [생성된정점, 도넛그래프, 막대그래프, 8자그래프]
    vector<pair<int, int>> vertex_degree(MAX_VERTEX, {0, 0}); // {out_degree, in_degree}
    vector<vector<int>> adjacent_list(MAX_VERTEX); // 인접 리스트
    
    // 간선의 수 기록
    for (const auto& edge : edges) {
        int start = edge[0];
        int end = edge[1];
        vertex_degree[start].first += 1; // out_degree 증가
        vertex_degree[end].second += 1;  // in_degree 증가
        adjacent_list[start].push_back(end); // 인접 리스트에 간선 추가
    }
    
    // 생성된 정점 찾기
    for (int vertex = 1; vertex < MAX_VERTEX; ++vertex) {
        // 들어오는 간선은 없고, 나가는 간선 수가 2가 이상인 정점
        if (vertex_degree[vertex].second == 0 && vertex_degree[vertex].first >= 2) {
            answer[0] = vertex;
            continue;
        }
    }
    
    int bar_graphs = 0; // 막대 그래프
    int eight_graphs = 0; // 8자 그래프
    
    // 생성된 정점에 연결된 간선 제거
    for (int vertex : adjacent_list[answer[0]]) {
        vertex_degree[vertex].second -= 1; // in_degree 감소
        // 크기가 1인 막대 그래프 찾기
        if (vertex_degree[vertex].first == 0 && vertex_degree[vertex].second == 0) {
            bar_graphs += 1;
        }
    }
    
    // 모든 정점을 돌면서 간선의 수를 확인
    for (int vertex = 1; vertex < MAX_VERTEX; ++vertex) {
        int out_degree = vertex_degree[vertex].first;
        int in_degree = vertex_degree[vertex].second;
        // 8자 그래프의 중심점인 경우
        if (out_degree == 2 && in_degree == 2) {
            eight_graphs += 1;
        }
        // 막대 그래프의 끝점인 경우
        else if (out_degree == 0 && in_degree == 1) {
            bar_graphs += 1;
        }
    }
    
    // 도넛 그래프의 수는 전체 그래프에서 막대 그래프와 8자 그래프를 제외해서 구함
    answer[1] = vertex_degree[answer[0]].first - bar_graphs - eight_graphs;
    answer[2] = bar_graphs;
    answer[3] = eight_graphs;
    
    return answer;
}