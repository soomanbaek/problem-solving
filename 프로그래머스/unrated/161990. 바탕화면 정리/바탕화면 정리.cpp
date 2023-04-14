#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int min_x = 100; // lux
    int min_y = 100; // luy
    int max_x = 0;   // rdx
    int max_y = 0;   // rdy
    
    for(int i=0; i<wallpaper.size(); ++i){
        for(int j=0; j<wallpaper[0].size(); ++j){
            if(wallpaper[i][j] == '#'){
                min_y = min(min_y, i);
                max_y = max(max_y, i+1);
                min_x = min(min_x, j);
                max_x = max(max_x, j+1);
            }
        }
    }
    answer.push_back(min_y);
    answer.push_back(min_x);
    answer.push_back(max_y);
    answer.push_back(max_x);
    
    return answer;
}