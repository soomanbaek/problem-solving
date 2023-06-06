#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll make_answer(vector<int> p, queue<ll> num, queue<ll> op){
    for(int i=0; i<p.size(); i++){
        int length = op.size();
        ll num1 = num.front();
        num.pop();
        for(int j=0; j<length; j++){
            if(op.front() == p[i]){
                op.pop();
                ll num2 = num.front();     num.pop();
                if(p[i] == 1)
                    num1 *= num2;
                else if(p[i] == 2)
                    num1 += num2;
                else if(p[i] == 3)
                    num1 -= num2;
            }
            else{
                num.push(num1);
                num1 = num.front();     num.pop();
                op.push(op.front());    op.pop();
            }
        }
        num.push(num1);
    }
    return abs(num.front());
}

ll solution(string expression) {
    ll answer = 0;

    string tmp = "";
    queue<ll> num, op;

    for(auto ch : expression){
        if(ch == '*' || ch == '+' || ch == '-'){
            num.push(stoi(tmp));
            tmp="";
            if(ch == '*')   op.push(1);
            else if(ch == '+')   op.push(2);
            else if(ch == '-')   op.push(3);
            continue;
        }
        tmp+=ch;
    }
    num.push(stoi(tmp));

    vector<int> p = {1,2,3};

    do{
        ll m = make_answer(p,num,op);
        answer = max(answer,m);
    }while(next_permutation(p.begin(), p.end()));

    return answer;
}