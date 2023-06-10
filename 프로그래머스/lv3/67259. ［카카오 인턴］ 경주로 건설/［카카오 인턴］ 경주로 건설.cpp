#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class car{
public:
    int x, y;
    int direction;
    int cost;
    car(int x, int y, int direction, int cost):x(x),y(y),direction(direction),cost(cost){}
};

int visited[26][26][4];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int solution(vector<vector<int>> board) {
    int answer = 987654321;
    int n = board.size()-1;
    for(int i=0; i<=n; i++)
        for(int j=0; j<=n; j++)
            for(int k=0; k<4; k++)
                visited[i][j][k] = 987654321;
    queue<car> Q;
    Q.push({0,0,1,0});
    Q.push({0,0,2,0});
    while(!Q.empty()){
        int x = Q.front().x;
        int y = Q.front().y;
        int direction = Q.front().direction;
        int cost = Q.front().cost;
        Q.pop();
        if(visited[x][y][direction] < cost)
            continue;
        visited[x][y][direction] = cost;
        if(x == n && y == n)
            answer = min(answer, cost);
        // go straight
        if(!(x+dx[direction]<0 || x+dx[direction]>n || y+dy[direction]<0 || y+dy[direction]>n))
            if(board[x+dx[direction]][y+dy[direction]] != 1)
                Q.push({x+dx[direction], y+dy[direction], direction, cost+100});
        // turn right
        Q.push({x, y, (direction+1)%4, cost+500});
        // turn left
        Q.push({x, y, (direction-1>=0? direction-1 : 3)%4, cost+500});
    }

    return answer;
}