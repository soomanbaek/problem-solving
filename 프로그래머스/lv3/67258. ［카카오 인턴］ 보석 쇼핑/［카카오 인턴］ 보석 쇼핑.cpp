#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

vector<int> solution(vector<string> gems) {
    queue<int> Q;
    vector<int> V;
    map<string,int> M;
    queue<int> ans;
    vector<int> answer(2);
    int cnt = 0;
    for(const auto& gem : gems){
        if(M.find(gem) == M.end())
            M[gem] = cnt++;
        Q.push(M[gem]);
    }
    V.resize(cnt);

    int start = 1;
    int end = 1;

    int len = 100001;
    int total = 0;
    while(!Q.empty()){
        int num = Q.front();
        Q.pop();
        ans.push(num);
        if(V[num] == 0)
            total += 1;
        V[num] += 1;
        while(!ans.empty() && V[ans.front()] > 1){
            V[ans.front()] -= 1;
            ans.pop();
            start += 1;
        }
        if(total == cnt && len > end - start){
            len = end - start;
            answer[0] = start;
            answer[1] = end;
        }
        end += 1;
    }
    return answer;
}