#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    
    vector<int> D(n+1, -1);
    vector<bool> visited(n+1, false);
    vector<vector<int>> E(n+1);
    queue<pair<int,int>> Q;
    
    for(auto& road: roads){
        E[road[0]].push_back(road[1]);
        E[road[1]].push_back(road[0]);
    }
    
    D[destination] = 0;
    visited[destination] = true;
    Q.push({destination, 0});
    while(!Q.empty()){
        int current = Q.front().first;
        int num = Q.front().second;
        Q.pop();
        D[current] = num;
        
        for(auto& next: E[current]){
            if(visited[next]) continue;
            Q.push({next, num + 1});
            visited[next] = true;
        }
    }
    for(auto source: sources){
        answer.push_back(D[source]);
    }
    
    return answer;
}