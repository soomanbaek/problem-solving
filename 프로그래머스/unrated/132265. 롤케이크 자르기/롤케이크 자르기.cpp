#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int leftTopping[1000001];
int rightTopping[1000001];

void makeLeftTopping(vector<int>& topping){
    set<int> S;
    for(int i=0; i<topping.size(); ++i){
        S.insert(topping[i]);
        leftTopping[i] = S.size();
    }
}

void makeRightTopping(vector<int>& topping){
    set<int> S;
    for(int i=topping.size()-1; i>=0; --i){
        S.insert(topping[i]);
        rightTopping[i] = S.size();
    }
}

int solution(vector<int> topping) {
    int answer = 0;
    
    makeLeftTopping(topping);
    makeRightTopping(topping);
    
    for(int i=0; i<topping.size()-1; ++i){
        if(leftTopping[i] == rightTopping[i+1])   answer+=1;
    }
    return answer;
}