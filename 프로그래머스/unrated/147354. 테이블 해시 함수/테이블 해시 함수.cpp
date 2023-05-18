#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    col -= 1; row_begin -= 1; row_end -= 1;
    static int c = col;
    
    sort(data.begin(), data.end(), [](const vector<int> &V1,const vector<int> &V2){
        if(V1[c] == V2[c])  return V1[0] > V2[0];
        return V1[c] < V2[c];
    });
    
    for(int row = row_begin; row<=row_end; ++row){
        int S = 0;
        for(int col = 0; col < data[row].size(); ++col){
            S += data[row][col]%(row+1);
        }
        answer ^= S;
    }
    
    return answer;
}