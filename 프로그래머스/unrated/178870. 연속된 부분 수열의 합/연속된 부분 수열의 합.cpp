#include <iostream>
#include <string>
#include <vector>

#define LIMIT 987654321

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2);
    int min_length = LIMIT;
    int sum = sequence[0];
    int s = 0, e = 0;
    while(s < sequence.size()){
        if(sum < k && e >= sequence.size())  break;
        if(sum == k){
            if(e - s < min_length){
                min_length = e - s;
                answer[0] = s;
                answer[1] = e;
            }
            e += 1;
            if(e < sequence.size())
                sum += sequence[e];
        }if(sum < k){
            e += 1;
            if(e < sequence.size())
                sum += sequence[e];
        }else{
            sum -= sequence[s];
            s += 1;
        }
    }
    return answer;
}