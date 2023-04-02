#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

class Plan{
public:
    string subject;
    int start_time;
    int remained_time;
    Plan(string subject, string start_time, string remained_time){
        this->subject = subject;
        this->start_time = convertStartTime(start_time);
        this->remained_time = convertRemainedTime(remained_time);
    }
    
    int convertStartTime(string start_time){
        char* hour = strtok((char*)start_time.c_str(), ":");
        char* second = strtok(NULL, ":");

        return stoi(hour)*60 + stoi(second);
    }
    
    int convertRemainedTime(string remained_time){
        return stoi(remained_time);
    }
};

struct compare{
    bool operator()(Plan& l, Plan& r){
        return l.start_time > r.start_time;
    }
};

priority_queue<Plan, vector<Plan>, compare> ready_queue;
stack<Plan> wait_stack;

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    for(auto& plan: plans){
        ready_queue.push({plan[0], plan[1], plan[2]});
    }
    
    Plan cur = ready_queue.top();
    ready_queue.pop();
    int time = cur.start_time;
    while(!ready_queue.empty()){
        Plan next = ready_queue.top();
        // 과제를 마쳤을 경우
        if(time + cur.remained_time <= next.start_time){
            answer.push_back(cur.subject);
            if(!wait_stack.empty()){
                time += cur.remained_time;
                cur = wait_stack.top();
                wait_stack.pop();
                continue;
            }
        }else{  // 과제를 마치지 못하였을 경우
            cur.remained_time -= (next.start_time - time);
            wait_stack.push(cur);
        }
        // 과제를 마쳤는데, stack이 비어있거나
        // 과제를 마쳤을 경우
        ready_queue.pop();
        cur = next;
        time = cur.start_time;
    }
    answer.push_back(cur.subject);
    while(!wait_stack.empty()){
        answer.push_back(wait_stack.top().subject);
        wait_stack.pop();
    }
    return answer;
}