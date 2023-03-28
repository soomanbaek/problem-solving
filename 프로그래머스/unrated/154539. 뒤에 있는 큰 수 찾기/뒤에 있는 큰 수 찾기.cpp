#include <string>
#include <vector>
#include <queue>

using namespace std;

class Number{
public:
    int num;
    int idx;
    Number(int n, int i){
        this -> num = n;
        this -> idx = i;
    }
};

struct compare{
    bool operator()(Number& a, Number& b){
        return a.num > b.num;
    }
};

vector<int> solution(vector<int> numbers) {
    int N = numbers.size();
    vector<int> answer(N);
    priority_queue<Number, vector<Number>, compare> PQ;
    
    for(int i=0; i<N; ++i){
        int number = numbers[i];
        while(!PQ.empty() && PQ.top().num < number){
            answer[PQ.top().idx] = number;
            PQ.pop();
        }
        PQ.push({number, i});
    }
    while(!PQ.empty()){
        answer[PQ.top().idx] = -1;
        PQ.pop();
    }
    return answer;
}