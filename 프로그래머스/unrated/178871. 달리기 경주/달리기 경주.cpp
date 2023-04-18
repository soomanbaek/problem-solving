#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    int N = players.size();
    int M = callings.size();
    vector<string> answer;
    map<string, int> name_rank;
    map<int, string> rank_name;
    
    for(int i=0; i<N; ++i){
        name_rank.insert({players[i], i+1});
        rank_name.insert({i+1, players[i]});
    }
    for(auto& calling: callings){
        // 앞사람이 뒤로 밀려남
        string front_name = rank_name[name_rank[calling]-1];
        int front_rank = name_rank[calling];
        
        // 앞으로 전진
        rank_name[name_rank[calling] - 1] = calling;
        name_rank[calling] -= 1;
        
        rank_name[front_rank] = front_name;
        name_rank[front_name] = front_rank;
    }
    
    for(auto rn : rank_name){
        answer.push_back(rn.second);
    }
    
    return answer;
}