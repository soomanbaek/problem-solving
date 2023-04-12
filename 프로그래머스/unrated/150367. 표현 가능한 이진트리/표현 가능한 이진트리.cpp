#include <iostream>
#include <string>
#include <vector>

using namespace std;

string convertDecimalToBinary(long long number){
    string ret = "";
    while(number){
        if(number%2)    ret = "1"+ret;
        else            ret = "0"+ret;
        number /= 2;
    }
    return ret;
}

bool isHaveChildren(string& num, int idx, int carry, bool& isSuccess){
    if(idx%2 == 0)   return num[idx] == '1';  // 리프 노드
    
    bool children = false;
    children |= isHaveChildren(num, idx-carry, carry/2, isSuccess);
    children |= isHaveChildren(num, idx+carry, carry/2, isSuccess);
    if(num[idx] == '0' && children){
        isSuccess = false;
    }
    return (children || num[idx] == '1');
}

bool isAllzero(string num){
    for(int i=0; i<num.length(); ++i){
        if(num[i] == '1')   return false;
    }
    return true;
}

bool isSuccess(string num){
    if(num.length() == 1 || isAllzero(num)) return true;
    int midIdx = num.size() / 2;
    string left = num.substr(0, midIdx);
    string right = num.substr(midIdx+1);
    if ((num[midIdx] == '1') && isSuccess(left) && isSuccess(right)) return true;
    return false;
}

int isPossibleToShowBinaryTree(long long number){
    if(number == 1) return 1;
    // number -> num(binary_number)
    string num = convertDecimalToBinary(number);
    
    // 포화 이진트리로 만들기
    long long carry = 1;
    while(carry <= num.length()){
        carry += carry;
    }
    while(num.length() < carry - 1){
        num = "0" + num;
    }
    
    // 자식이 1인데 본인은 0인 경우 false
    bool isSuccess = true;
    isHaveChildren(num, num.length()/2, (num.length()+1)/4,isSuccess);
    
    return isSuccess;
    // return isSuccess(num);
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    for(auto& number : numbers){
        answer.push_back(isPossibleToShowBinaryTree(number));
    }
    return answer;
}