#include <iostream>
#include <string>
#include <vector>

using namespace std;

pair<int,int> D[100001];

void init(){
    D[50] = {1,1};
    for(int i=1; i<=20; ++i){
        D[i] = {1,1};  D[2*i] = {1,0};  D[3*i] = {1,0};
    }
}

void calc(int num){
    if(D[num].first != 0)   return;
    for(int i=1; i<=20; ++i){
        for(int j=1; j<=3; ++j){
            int c = i*j;
            if(num-c <= 0)  continue;
            calc(num-c);
            if(D[num].first == 0 || D[num].first > D[num-c].first + D[c].first){
                D[num].first = D[num-c].first + D[c].first;
                D[num].second = D[num-c].second + D[c].second;
            }else if(D[num].first == D[num-c].first + D[c].first){
                if(D[num].second < D[num-c].second + D[c].second){
                    D[num].second = D[num-c].second + D[c].second;
                }
            }
        }
    }
    int c= 50;
    if(num-c > 0){
        calc(num-c);
        if(D[num].first == 0 || D[num].first > D[num-c].first + D[c].first){
            D[num].first = D[num-c].first + D[c].first;
            D[num].second = D[num-c].second + D[c].second;
        }else if(D[num].first == D[num-c].first + D[c].first){
            if(D[num].second < D[num-c].second + D[c].second){
                D[num].second = D[num-c].second + D[c].second;
            }
        }
    }
}

vector<int> solution(int target) {
    vector<int> answer;
    
    init(); // 1. 한번에 끝내는 경우로 D 초기화
    calc(target);
    answer.push_back(D[target].first);
    answer.push_back(D[target].second);
    
    return answer;
}