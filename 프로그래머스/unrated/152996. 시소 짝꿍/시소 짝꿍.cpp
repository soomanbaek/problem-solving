#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isExistTarget(int start, int end, vector<int>& weights, int target){
    int left = start;
    int right = end;
    int mid;
    while(left<=right){
        mid = (left + right) / 2;
        if(weights[mid] == target)    return true;
        if(weights[mid] < target)   left = mid + 1;
        else    right = mid - 1;
    }
    return false;
}

int getPartnerNum(int start, int end, vector<int>& weights, int target){
    if(isExistTarget(start, end, weights, target))
        return upper_bound(weights.begin()+start, weights.end(), target) - lower_bound(weights.begin()+start, weights.end(), target);
    return 0;
}

long long solution(vector<int> weights) {
    long long answer = 0;
    // 1. weigths 정렬
    sort(weights.begin(), weights.end());
    for(int i=0; i<weights.size()-1; ++i){
        int weight = weights[i];
        answer += getPartnerNum(i+1, weights.size()-1, weights, weight);
        if(!((weight*4)%3))
            answer += getPartnerNum(i+1, weights.size()-1, weights, weight*4/3);
        if(!((weight*3)%2))
            answer += getPartnerNum(i+1, weights.size()-1, weights, weight*3/2);
        answer += getPartnerNum(i+1, weights.size()-1, weights, weight*2);
    }
    return answer;
}