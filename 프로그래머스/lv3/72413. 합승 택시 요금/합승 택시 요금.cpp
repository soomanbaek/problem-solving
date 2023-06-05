#include <iostream>
#include <string>
#include <vector>

#define MAX 20000001

using namespace std;

typedef pair<int,int> pii;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = MAX;
    vector<vector<int>> dist(n+1, vector<int>(n+1, MAX));

    for(int i = 1; i<= n; i++)
        dist[i][i] = 0;
    for(auto& fare : fares){
        dist[fare[0]][fare[1]] = fare[2];
        dist[fare[1]][fare[0]] = fare[2];
    }
    for(int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (dist[i][k] != MAX && dist[k][j] != MAX)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }
    for(int i=1; i<=n; i++){
        int total = dist[s][i] + dist[i][a] + dist[i][b];
        answer = min(total, answer);
    }
    return answer;
}