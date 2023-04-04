#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dr[4] = {-1, 0, 1, 1};
int dc[4] = {1, 1, 0, 1};

vector<string> board;

// 'O' 갯수는 'X' 갯수와 같거나 하나 크다.
int getNum(char T){
    int num = 0;
    for(int r=0; r<3; ++r){
        for(int c=0; c<3; ++c){
            if(board[r][c] == T)    num += 1;
        }
    }
    return num;
}

bool rule1(){
    int num_O = getNum('O');
    int num_X = getNum('X');
    if(num_O == num_X+1 || num_O == num_X)
        return true;
    return false;
}

bool isThreeConnect(int r, int c, char token){
    for(int d=0; d<4; ++d){
        int nr = r+dr[d];
        int nc = c+dc[d];
        int nnr = r+2*dr[d];
        int nnc = c+2*dc[d];
        
        if(nr<0 || nr>=3 || nc<0 || nc>= 3) continue;
        if(nnr<0 || nnr>=3 || nnc<0 || nnc>=3)  continue;
        
        if(board[nr][nc] == token && board[nnr][nnc] == token)
            return true;
    }
    return false;
}

bool rule2(){
    bool isThreeO = false;
    bool isThreeX = false;
    for(int r=0; r<3; ++r){
        if(board[r][0] == '.') continue;
        if(isThreeConnect(r,0,board[r][0])){
            if(board[r][0] == 'O')  isThreeO = true;
            else    isThreeX = true;
        }
    }
    for(int c=1; c<3; ++c){
        if(board[0][c] == '.') continue;
        if(isThreeConnect(0,c,board[0][c])){
            if(board[0][c] == 'O')  isThreeO = true;
            else    isThreeX = true;
        }
    }
    
    int num_O = getNum('O');
    int num_X = getNum('X');
    
    // X가 3개로 성공 시, O가 3개이면 안된다.
    if(isThreeX && isThreeO)    return false;
    
    // X가 이미 완성되었는데, 진행하면 안된다.
    if(isThreeX && (num_O > num_X))   return false;
    
    if(isThreeO && (num_O == num_X))    return false;
    
    return true;
}

int solution(vector<string> _board) {
    board = _board;
    int answer = 1;
    
    // 'O'를 표시할 차례인데 'X'를 표시하거나 반대로 'X'를 표시할 차례인데 'O'를 표시하는 경우
    if(!rule1()) answer = 0;
    // 선공이나 후공이 승리해서 게임이 종료되었음에도 그 게임을 진행하는 경우
    if(!rule2()) answer = 0;
    
    return answer;
}