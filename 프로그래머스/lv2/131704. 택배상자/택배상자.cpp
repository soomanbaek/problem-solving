#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

queue<int> Q;
stack<int> S;

int solution(vector<int> order) {
    int answer = 0;
    for(int i=1; i<=order.size(); ++i) Q.push(i);
    
    int n = 0;
    while(n < order.size()){
        if(!S.empty() && S.top() == order[n]){
            S.pop();
            n += 1;
            answer += 1;
            continue;
        }
        if(!Q.empty()){
            while(order[n] > Q.front()){
                S.push(Q.front());
                Q.pop();
            }
            if(order[n] == Q.front()){
                Q.pop();
                n += 1;
                answer += 1;
            }else{
                break;
            }
            continue;
        }
        break;
    }
    answer = n;
    
    
    
    return answer;
}