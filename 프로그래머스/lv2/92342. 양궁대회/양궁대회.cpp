#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> info;
vector<int> answer_V(11);

int max_point = 0;

void getPoint(int n, int remained_arrow, int point, vector<int> _V){
    if(n == 10){
        _V[10] += remained_arrow;
        getPoint(n+1, 0, point, _V);
        return;
    }
    if(n == 11){
        if(max_point == point){
            for(int i=10; i>=0; --i){
                if(answer_V[i] > _V[i]){
                    return;
                }else if(answer_V[i] < _V[i]){
                    answer_V = _V;
                    return;
                }
            }
        }
        else if(max_point < point){
            max_point = point;
            answer_V = _V;
        }
        return;
    }
    // n번 과녁을 맞추는 경우
    if(remained_arrow > info[n]){
        int spent_arrow = info[n] + 1;
        int gain_point = 10 - n;

        if(info[n]) gain_point *= 2;
        
        vector<int> V(_V);
        V[n] += spent_arrow;
        getPoint(n+1, remained_arrow - spent_arrow, point + gain_point, V);
    }
    vector<int> V(_V);
    // n번 과녁을 맞추지 않는 경우
    getPoint(n+1, remained_arrow, point, V);
}

vector<int> solution(int remained_arrow, vector<int> _info) {
    info = _info;
    vector<int> answer;
    
    // apeach 포인트 계산
    int apeach_point = 0;
    for(int i=0; i<info.size(); ++i){
        if(info[i])
            apeach_point += (10-i);
    }
    
    getPoint(0, remained_arrow, 0, vector<int>(11));
    
    if(max_point <= apeach_point)   answer.push_back(-1);
    else    answer = answer_V;
    
    return answer;
}