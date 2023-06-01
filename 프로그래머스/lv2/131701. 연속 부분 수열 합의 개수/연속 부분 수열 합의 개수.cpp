#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    
    set<int> S;
    int n = elements.size();
    for(int i=0; i<n - 1; ++i){
        elements.push_back(elements[i]);
    }
    
    for(int i=0; i<n; ++i){
        int sum = 0;
        for(int j=i; j<i+n; ++j){
            sum += elements[j];
            S.insert(sum);
        }
    }
    
    answer = S.size();
    return answer;
}