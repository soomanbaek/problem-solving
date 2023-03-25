#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

long long solution(vector<int> sequence) {
    long long answer = 0;
    long long PSMS = 0;   // Positive Start Max Sum
    long long NSMS = 0;  // Negative Start Max Sum
    for(int i=0; i<sequence.size(); ++i){
        if(i%2){    // 홀 수 일경우 (NSMS가 +)
            PSMS = PSMS + sequence[i]*(-1) > sequence[i]*(-1)? PSMS + sequence[i]*(-1) : sequence[i]*(-1);
            NSMS = NSMS + sequence[i] > sequence[i]? NSMS + sequence[i] : sequence[i];
        }
        else{
            PSMS = PSMS + sequence[i] > sequence[i] ? PSMS + sequence[i] : sequence[i];
            NSMS = NSMS + sequence[i]*(-1) > sequence[i]*(-1)? NSMS + sequence[i]*(-1) : sequence[i]*(-1);
        }
        long long maxNum = PSMS > NSMS ? PSMS : NSMS;
        answer = answer > maxNum ? answer : maxNum;
    }
    return answer;
}