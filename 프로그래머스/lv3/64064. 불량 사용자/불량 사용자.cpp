#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

unordered_map<string,int> M;
unordered_set<int> S;

int make_answer(vector<string> V[], int banned_size, int index, int visit){
    if(index == banned_size) {
        if(S.find(visit) != S.end()) {
            return 0;
        }
        S.insert(visit);
        return 1;
    }
    int sum = 0;
    for(auto& v: V[index]){
        if((visit & (1<<M[v])) == (1<<M[v])) {
            continue;
        }
        sum += make_answer(V, banned_size, index + 1, visit + (1<<M[v]));
    }
    return sum;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    vector<string> V[8];
    for(int i=0; i<user_id.size(); i++)
        M[user_id[i]] = i;

    for(int i=0; i<banned_id.size(); i++){
        for(auto& id : user_id){
            if(id.size() != banned_id[i].size())
                continue;
            bool success = true;
            for(int k=0; k<id.size(); k++){
                if(banned_id[i][k] == '*')
                    continue;
                if(id[k] != banned_id[i][k]){
                    success = false;
                    break;
                }
            }
            if(success) {
                V[i].push_back(id);
            }
        }
    }
    answer = make_answer(V,banned_id.size(),0, 0);
    return answer;
}