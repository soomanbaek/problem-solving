#include <string>
#include <vector>

using namespace std;

int GCD(int a, int b){
    if(a%b == 0)
        return b;
    return GCD(b, a%b);
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    
    int GCDA = arrayA[0];
    for(auto &el : arrayA){
        GCDA = GCD(el, GCDA);
    }
    for(auto &el : arrayB){
        if(el%GCDA == 0){
            GCDA = -1;
            break;
        }
    }
    if(GCDA != -1) 
        answer = GCDA;
    
    int GCDB = arrayB[0];
    for(auto &el : arrayB){
        GCDB = GCD(el, GCDB);
    }
    for(auto &el : arrayA){
        if(el%GCDB == 0){
            GCDB = -1;
            break;
        }
    }
    if(GCDB != -1)  
        answer = max(answer, GCDB);
    
    return answer;
}