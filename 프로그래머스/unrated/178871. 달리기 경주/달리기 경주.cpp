#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    // 1. mapping [name - index]
    map<string, int> M;
    for(int i=0; i<players.size(); ++i){
        M[players[i]] = i; // name(string) - index(int) 매핑
    }
    // 2. callings 순회
    for(auto& player : callings){
        int index = M[player];
        string front_player = players[index-1];
        M[player] -= 1;
        M[front_player] += 1;
        
        string temp = players[index];
        players[index] = players[index-1];
        players[index-1] = temp;
    }
    
    // 3. answer = players
    answer = players;
    
    return answer;
}