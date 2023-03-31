#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Pos{
public:
    int r;
    int c;
    int num;
    Pos(int r, int c, int n){
        this->r = r;
        this->c = c;
        this->num = n;
    }
};

bool visited[101][101];
int dr[4] = {-1, 0, 0, 1};
int dc[4] = {0, -1, 1, 0};
int N, M;

int solve (queue<Pos>& Q, vector<string>& board){
    int answer = -1;
    while(!Q.empty()){
        Pos cur = Q.front();    Q.pop();
        if(board[cur.r][cur.c] == 'G'){
            answer = cur.num;
            break;
        }
        for(int d=0; d<4; ++d){
            int nr = cur.r + dr[d];
            int nc = cur.c + dc[d];
            
            if(nr<0 || nr>=N || nc<0 || nc>=M)  continue;
            
            while(!(nr<0 || nr>=N || nc<0 || nc>=M)){
                if(board[nr][nc] == 'D') break;
                nr += dr[d];
                nc += dc[d];
            }
            nr -= dr[d];
            nc -= dc[d];
            if(visited[nr][nc]) continue;
            if(board[nr][nc] == 'D') continue;
            visited[nr][nc] = true;
            Q.push({nr, nc, cur.num + 1});
        }
    }
    return answer;
}
int solution(vector<string> board) {
    int answer = -1;
    N = board.size(); M = board[0].size();
    queue<Pos> Q;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            if(board[i][j] == 'R')  Q.push({i, j, 0});
        }
    }
    answer = solve(Q, board);
    
    return answer;
}