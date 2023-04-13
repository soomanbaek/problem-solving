#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, M;

// d, l, r, u
int dr[4] = {1, 0, 0, -1};
int dc[4] = {0, -1, 1, 0};

int dir[4];

void setDirectionNum(int y, int x, int r, int c){
    dir[0] = N-y;
    dir[1] = x-1;
    dir[2] = c-1;
    dir[3] = N-r;
}
    
string solution(int n, int m, int y, int x, int r, int c, int k) {
    N = n; M = m;
    string answer = "";
    string wrong_answer = "impossible";
    
    setDirectionNum(y, x, r, c);
    // k만큼 움직였을 때 도달할 수 없는경우 
    int shortestRouteLength = abs(y-r) + abs(x-c);
    if(k < shortestRouteLength) return wrong_answer;
    if((k - shortestRouteLength) % 2) return wrong_answer;
    
    string route = "";
    
    int dir_num = dir[0] + dir[1] + dir[2] + dir[3];
    if(dir_num < k){
        for(int i=0; i<dir[0]; ++i) route += 'd';
        for(int i=0; i<dir[1]; ++i) route += 'l';
        for(int i=0; i<dir[2]; ++i) route += 'r';
        for(int i=0; i<dir[3]; ++i) route += 'u';
        
        while(dir_num < k){
            route = route.substr(0, dir[0]+dir[1])+"rl"+route.substr(dir[0]+dir[1]);
            dir_num += 2;
        }
    }
    else{
        while(dir_num > k){
            if(dir[1]>0 && dir[2]>0){
                dir[1] -= 1;
                dir[2] -= 1;
            }else{
                dir[0] -= 1;
                dir[3] -= 1;
            }
            dir_num -= 2;
        }
        for(int i=0; i<dir[0]; ++i) route += 'd';
        for(int i=0; i<dir[1]; ++i) route += 'l';
        for(int i=0; i<dir[2]; ++i) route += 'r';
        for(int i=0; i<dir[3]; ++i) route += 'u';
    }
    answer = route;
    return answer;
}