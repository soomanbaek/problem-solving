#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define INF 987654321

using namespace std;

int DP[100001][10][10];
int weight[10][10] = {
    {1, 7, 6, 7, 5, 4, 5, 3, 2, 3},
    {7, 1, 2, 4, 2, 3, 5, 4, 5, 6},
    {6, 2, 1, 2, 3, 2, 3, 5, 4, 5},
    {7, 4, 2, 1, 5, 3, 2, 6, 5, 4},
    {5, 2, 3, 5, 1, 2, 4, 2, 3, 5},
    {4, 3, 2, 3, 2, 1, 2, 3, 2, 3},
    {5, 5, 3, 2, 4, 2, 1, 5, 3, 2},
    {3, 4, 5, 6, 2, 3, 5, 1, 2, 4},
    {2, 5, 4, 5, 3, 2, 3, 2, 1, 2},
    {3, 6, 5, 4, 5, 3, 2, 4, 2, 1}
};

int solution(string numbers) {
    fill_n(&DP[0][0][0], sizeof(DP)/sizeof(int), INF);
    
    int answer = INF;
    DP[0][4][6] = 0;
    for(int i=0; i<numbers.length(); ++i){
        int N = numbers[i] - '0';
        for(int y=0; y<10; ++y){
            for(int x=0; x<10; ++x){
                if(DP[i][y][x] == INF)   continue;
                if(x != N)
                    DP[i+1][N][x] = min(DP[i+1][N][x], DP[i][y][x] + weight[y][N]);
                if(y != N)
                    DP[i+1][y][N] = min(DP[i+1][y][N], DP[i][y][x] + weight[x][N]);
            }
        }
    }
    for(int y=0; y<10; ++y){
        for(int x=0; x<10; ++x){
            answer = min(answer, DP[numbers.length()][y][x]);
        }
    }
    
    return answer;
}