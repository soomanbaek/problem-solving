#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

void reverseBoardByColumn(vector<vector<int>>& board, int c){
    for(int r=0; r<board.size(); ++r){
        board[r][c] = !board[r][c];
    }
}

int calculateReverseNum(vector<vector<int>> board, vector<vector<int>>& target){
    int reverse_num = 0;
    int N = board.size();
    int M = board[0].size();
    
    // 행을 기준으로 열 뒤집기
    for(int c=0; c<M; ++c){
        if(board[0][c] != target[0][c]){
            reverse_num += 1;
            reverseBoardByColumn(board, c);
        }
    }
    // 모든 열을 검색하며 목표와 전부 같거나 전부 다른지 확인 (만약 그렇지 않으면 -1 반환)
    // 전부 다른경우 answer += 1
    for(int r=0; r<N; ++r){
        int board_bit = 0;
        int target_bit = 0;
        for(int c=0; c<M; ++c){
            board_bit += board[r][c]*pow(2,c);
            target_bit += target[r][c]*pow(2,c);
        }
        if(board_bit != target_bit){
            if(board_bit + target_bit != pow(2, M) - 1) return -1;
            reverse_num += 1;
        }
    }
    return reverse_num;
}
int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    int answer = 0;
    int N = beginning.size();
    int M = beginning[0].size();
    
    // 1. 첫 행을 뒤집지 않은 경우
    int answer1 = calculateReverseNum(beginning, target);
    // 2. 첫 행을 뒤집은 경우
    for(int i=0; i<M; ++i){
        beginning[0][i] = !beginning[0][i];
    }
    int answer2 = calculateReverseNum(beginning, target) + 1;
    
    answer = min(answer1, answer2);
    
    return answer;
}