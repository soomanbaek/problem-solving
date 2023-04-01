#include <string>
#include <vector>
#define LIMIT 987654321

using namespace std;

int getFatigue(int pick, string mineral){
    int fatigue = 1;
    if(pick == 1){
        if(mineral == "diamond")    fatigue = 5;
    }else if(pick == 2){
        if(mineral == "iron")       fatigue = 5;
        if(mineral == "diamond")    fatigue = 25;
    }
    return fatigue;
}

int getFatigueSum(int n, int pick, vector<string>& minerals){
    int fatigue_sum = 0;
    for(int i=0; i<5; ++i){
        if(n+i >= minerals.size()) break;
        fatigue_sum += getFatigue(pick, minerals[n+i]);
    }
    return fatigue_sum;
}

int dfs(int n, vector<int> picks, vector<string>& minerals){
    if(n >= minerals.size())  return 0;
    if(picks[0] == 0 && picks[1] == 0 && picks[2] == 0) return 0;
    int min_total_fatigue = LIMIT;
    for(int pick=0; pick<3; ++pick){
        if(picks[pick] == 0)   continue;
        picks[pick] -= 1;
        int total_fatigue = getFatigueSum(n, pick, minerals) + dfs(n+5, picks, minerals);
        picks[pick] += 1;
        min_total_fatigue = min(min_total_fatigue, total_fatigue);
    }
    return min_total_fatigue;
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = -1;
    answer = dfs(0, picks, minerals);
    if(answer == LIMIT) answer = -1;
    return answer;
}