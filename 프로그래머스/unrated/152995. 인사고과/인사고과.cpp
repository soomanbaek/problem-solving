#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Employee{
public:
    int num;
    int work_attitude;
    int peer_review;
    int total_score;
    Employee(int n, int w, int p){
        this -> num = n;
        this -> work_attitude = w;
        this -> peer_review = p;
        this -> total_score = w + p;
    };
};

class EmployeeCompareWithTotal{
public:
    bool operator()(Employee& a, Employee& b){
        return a.total_score < b.total_score;
    };
};

bool employeeCompareWithIncentive(Employee& a, Employee& b){
    if(a.work_attitude == b.work_attitude)
        return a.peer_review > b.peer_review;
    return a.work_attitude > b.work_attitude;
};

int solution(vector<vector<int>> scores) {
    // 1. work_attitude를 기준으로 정렬된 employee_list 생성
    int employee_num = 0;
    vector<Employee> employee_list;
    for(auto score: scores){
        employee_list.push_back({employee_num++, score[0], score[1]});
    }
    sort(employee_list.begin(), employee_list.end(), employeeCompareWithIncentive);

    // 2. 인센티브를 받지 못하는 employee 필터
    priority_queue<Employee, vector<Employee>, EmployeeCompareWithTotal> PQ;

    int cur_work_attitude = employee_list[0].work_attitude;
    int max_peer_review = 0;
    int cur_max_peer_review = employee_list[0].peer_review;

    for(auto employee: employee_list){
        if(employee.work_attitude != cur_work_attitude) { // work_attitude의 경계선
            max_peer_review = max(max_peer_review, cur_max_peer_review);
            cur_max_peer_review = employee.peer_review;
            cur_work_attitude = employee.work_attitude;
        }
        // 인센티브를 받지 못할 경우
        if(max_peer_review > employee.peer_review){
            if(employee.num == 0)   
                return -1;  // 완호가 인센티브를 받지 못할 경우
            continue;
        }
        PQ.push(employee);
    }

    // 3. 인센티브 총 합을 통해 순위 매김
    int rank = 1;
    int rank_carry = 0;
    int cur_total = PQ.top().total_score;
    while(!PQ.empty()){
        Employee employee = PQ.top();   PQ.pop();
        if(employee.total_score == cur_total){
            rank_carry += 1;
        }
        else {
            rank += rank_carry;
            rank_carry = 1;
            cur_total = employee.total_score;
        }
        if(employee.num == 0)   return rank;
    }
    return -1;
}