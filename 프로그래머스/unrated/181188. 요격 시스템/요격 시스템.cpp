#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Target{
public:
    int start;
    int end;
    Target(int start, int end){
        this->start = start;
        this->end = end;
    }
};

struct compare{
    bool operator()(const Target& l, const Target& r) const{
        if(l.start == r.start)  return l.end < r.end;
        return l.start < r.start;
    }
};

int solution(vector<vector<int>> _targets) {
    int answer = 0;
    // 1. vector<vector<int>> -> vector<Target>
    vector<Target> targets;
    for(const auto& _target: _targets){
        targets.push_back({_target[0], _target[1]});
    }
    
    // 2. vector<Target> 정렬
    sort(targets.begin(), targets.end(), compare());
    
    // 3. targets 순차
    int candidate_pos = 0;
    for(const auto& target: targets){
        if(target.start >= candidate_pos){
            answer += 1;
            candidate_pos = target.end;
            continue;
        }
        candidate_pos = min(candidate_pos, target.end);
    }
    return answer;
}