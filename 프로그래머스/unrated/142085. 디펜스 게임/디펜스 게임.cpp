#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue<int, vector<int>, less<int>> PQ;
    
    for(auto &enemy_num: enemy){
        PQ.push(enemy_num);
        if(n < enemy_num){
            if(k == 0)  break;
            n += PQ.top();  PQ.pop();
            k -= 1;
        }
        n -= enemy_num;
        answer += 1;
    }
    return answer;
}