#include <iostream>
#include <string>
#include <vector>
#include <set>

#define LIMIT 987654321111

typedef long long ll;

using namespace std;

class Point{
public:
    ll y;
    ll x;
    Point(ll y, ll x){
        this->y = y;
        this->x = x;
    }
    
    bool operator<(const Point& target) const{
        if(y == target.y) return x < target.x;
        return y < target.y;
    }
};

// 전역 변수
set<Point> S;

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    
    ll max_X = -1*LIMIT;
    ll min_X = LIMIT;
    ll max_Y = -1*LIMIT;
    ll min_Y = LIMIT;
    
    // 1. 모든 직선들 순회하면서 교차점 구하기
    for(int i=0; i<line.size(); ++i){
        for(int j=i+1; j<line.size(); ++j){
            if((ll)line[i][0]*(ll)line[j][1] == (ll)line[i][1]*(ll)line[j][0])    continue;
            
            ll top_x = (ll)line[i][1]*(ll)line[j][2] - (ll)line[i][2]*(ll)line[j][1];
            ll bot_x = (ll)line[i][0]*(ll)line[j][1] - (ll)line[i][1]*(ll)line[j][0];
            if(top_x % bot_x)   continue;
            ll x = top_x/bot_x;
            
            ll top_y = (ll)line[i][2]*(ll)line[j][0] - (ll)line[i][0]*(ll)line[j][2];
            ll bot_y = (ll)line[i][0]*(ll)line[j][1] - (ll)line[i][1]*(ll)line[j][0];
            if(top_y % bot_y)   continue;
            ll y = top_y/bot_y;
            
            max_X = max(max_X, x);
            min_X = min(min_X, x);
            max_Y = max(max_Y, y);
            min_Y = min(min_Y, y);
            
            S.insert({y, x});
        }
    }
    // 좌표 그리기
    for(ll i=0; i<=max_Y-min_Y; ++i){
        answer.push_back("");
        for(ll j=0; j<=max_X-min_X; ++j){
            answer[i].push_back('.');
        }
    }
    for(auto&s: S){
        answer[max_Y-s.y][s.x-min_X] = '*';
    }
    return answer;
}