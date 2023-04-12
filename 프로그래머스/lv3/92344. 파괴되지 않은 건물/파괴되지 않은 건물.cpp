#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

class Point{
public:
    int y;
    int x;
    int degree;
    Point(int y, int x, int degree){
        this->y = y;
        this->x = x;
        this->degree = degree;
    }
};

struct compare{
    bool operator()(Point& l, Point& r){
        if(l.y == r.y)  return l.x > r.x;
        return l.y > r.y;
    }
};

priority_queue<Point,vector<Point>, compare> attack;
priority_queue<Point,vector<Point>, compare> heal;

int N, M;
int attack_weight[1001];
int heal_weight[1001];
int attack_point[1001][1001];
int heal_point[1001][1001];

void makePQ(vector<vector<int>>& skills){
    for(auto& skill: skills){
        if(skill[0] == 1){
            attack_point[skill[1]][skill[2]] += skill[5];
            if(skill[3]+1 < N && skill[4]+1 < M)
                attack_point[skill[3]+1][skill[4]+1] += skill[5];
            if(skill[4]+1 < M)
                heal_point[skill[1]][skill[4]+1] += skill[5];
            if(skill[3]+1 < N)
                heal_point[skill[3]+1][skill[2]] += skill[5];
        }else{
            heal_point[skill[1]][skill[2]] += skill[5];
            if(skill[3]+1 < N && skill[4]+1 < M)
                heal_point[skill[3]+1][skill[4]+1] += skill[5];
            if(skill[4]+1 < M)
                attack_point[skill[1]][skill[4]+1] += skill[5];
            if(skill[3]+1 < N)
                attack_point[skill[3]+1][skill[2]] += skill[5];
        }
    }
}

int solution(vector<vector<int>> board, vector<vector<int>> skills) {
    int answer = 0;
    N = board.size();
    M = board[0].size();
    
    makePQ(skills);
    
    for(int i=0; i<N; ++i){
        int heal_stack = 0;
        int attack_stack = 0;
        for(int j=0; j<M; ++j){
            attack_stack += attack_point[i][j];
            heal_stack += heal_point[i][j];
            
            attack_weight[j] += attack_stack;
            heal_weight[j] += heal_stack;
            
            board[i][j] += (heal_weight[j] - attack_weight[j]);
            
            if(board[i][j]>0) answer += 1;
        }
    }
    return answer;
}