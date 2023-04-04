#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<string> maps;

int dr[4] = {-1, 0, 0, 1};
int dc[4] = {0, -1, 1, 0};

class Pos{
public:
    int r;
    int c;
    int n;
    Pos(int r, int c, int n){
        this->r = r;
        this->c = c;
        this->n = n;
    }
};

void init(vector<string> _maps){
    maps = _maps;
    N = maps.size();
    M = maps[0].size();
}

pair<int,int> getPos(char T){
    for(int r=0; r<N; ++r){
        for(int c=0; c<M; ++c){
            if(maps[r][c] == T)
                return {r, c};
        }
    }
}

int getDistance(int sr, int sc, char target){
    vector<vector<bool>> visited(N, vector<bool>(M));
    // bool visited[N][M];
    queue<Pos> Q;
    Q.push({sr, sc, 0});
    visited[sr][sc] = true;
    // for(int i=0; i<N; ++i){
    //     for(int j=0; j<M; ++j){
    //         cout<<visited[i][j];
    //     }
    //     cout<<'\n';
    // }
    
    while(!Q.empty()){
        Pos cur = Q.front();    Q.pop();
        if(maps[cur.r][cur.c] == target)
            return cur.n;
        
        for(int d=0; d<4; ++d){
            int nr = cur.r + dr[d];
            int nc = cur.c + dc[d];
            
            if(nr<0 || nr>=N || nc<0 || nc>=M)  continue;
            if(maps[nr][nc] == 'X') continue;
            if(visited[nr][nc]) continue;
            
            visited[nr][nc] = true;
            Q.push({nr, nc, cur.n+1});
        }
    }
    return -1;
}

int solution(vector<string> maps) {    
    init(maps);
    int answer = 0;
    
    pair<int, int> start_pos = getPos('S');
    pair<int, int> lever_pos = getPos('L');
    
    // start -> lever
    int dist = getDistance(start_pos.first, start_pos.second, 'L');
    if(dist == -1)  return -1;
    else answer += dist;
    // lever -> end
    dist = getDistance(lever_pos.first, lever_pos.second, 'E');
    if(dist == -1)  return -1;
    else answer += dist;
    
    return answer;
}