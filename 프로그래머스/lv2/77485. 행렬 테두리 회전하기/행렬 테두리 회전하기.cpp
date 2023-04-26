#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    vector<vector<int>> board(rows, vector<int>(columns));
    int num = 1;
    for(int i=0; i<rows; ++i){
        for(int j=0; j<columns; ++j)
            board[i][j] = num++;
    }
    for(auto query : queries){
        int y1, x1, y2, x2;
        y1 = query[0]-1;  x1 = query[1]-1;  y2 = query[2]-1;  x2 = query[3]-1;
        int y, x;
        y = y1;     x = x1;
        int pre = board[y][x];
        int temp;
        int min_num = pre;
        while(x < x2){
            x += 1;
            temp = board[y][x];
            board[y][x] = pre;
            pre = temp;
            min_num = min(min_num, temp);
        }
        while(y < y2){
            y += 1;
            temp = board[y][x];
            board[y][x] = pre;
            pre = temp;
            min_num = min(min_num, temp);
        }
        while(x > x1){
            x -= 1;
            temp = board[y][x];
            board[y][x] = pre;
            pre = temp;
            min_num = min(min_num, temp);
        }
        while(y > y1){
            y -= 1;
            temp = board[y][x];
            board[y][x] = pre;
            pre = temp;
            min_num = min(min_num, temp);
        }
        answer.push_back(min_num);
    }
    return answer;
}