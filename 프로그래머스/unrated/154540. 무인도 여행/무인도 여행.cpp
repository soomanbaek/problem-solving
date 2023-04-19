#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[101][101];
int N, M;
int dr[4] = {-1, 0, 0, 1};
int dc[4] = {0, -1, 1, 0};

int dfs(vector<string>& maps, int r, int c){
    int sum = (maps[r][c] - '0');
    visited[r][c] = true;
    for(int i=0; i<4; ++i){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr<0 || nr>=N || nc<0 || nc>=M)  continue;
        if(visited[nr][nc] || maps[nr][nc] == 'X') continue;
        sum += dfs(maps, nr, nc);
    }
    return sum;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    N = maps.size();
    M = maps[0].size();
    for(int r=0; r<N; ++r){
        for(int c=0; c<M; ++c){
            if(visited[r][c] || maps[r][c] == 'X')  continue;
            answer.push_back(dfs(maps, r, c));
        }
    }
    sort(answer.begin(), answer.end());
    
    if(answer.empty())  answer.push_back(-1);
    return answer;
}