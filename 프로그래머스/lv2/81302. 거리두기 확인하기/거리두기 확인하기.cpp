#include<iostream>
#include <string>
#include <vector>

using namespace std;

int dx[8] = {1, 2, 0, 0, 1 ,0, 0, 1};
int dy[8] = {0, 0, 1, 2, 1 ,-1 ,-2, -1};
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(const auto &place : places){
        bool flag = true;
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                if(place[i][j] != 'P')  continue;
                for(int k=0; k<8; k++){
                    int next_x = j + dx[k];
                    int next_y = i + dy[k];

                    if(next_x>=5 || next_y>=5 || next_y <0 || next_x <0)  continue;

                    if(place[next_y][next_x] == 'X' && (k == 0 || k == 2 || k == 5)){
                        k++;
                        continue;
                    }

                    if(k == 4 && place[i+1][j] == 'X' && place[i][j+1] == 'X')    continue;
                    if(k == 7 && place[i-1][j] == 'X' && place[i][j+1] == 'X')    continue;
                    if(place[next_y][next_x]=='P'){
                        flag = false;
                        break;
                    }
                }
                if(!flag)   break;
            }
            if(!flag)   break;
        }
        if(flag)
            answer.push_back(1);
        else
            answer.push_back(0);
    }
    return answer;
}