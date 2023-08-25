#include <iostream>
#include <string>
#include <vector>

using namespace std;

string make_answer(string p){
    string u = "";
    string v = "";

    if(p=="")
        return "";
    int pair = 0;

    int i;
    bool is_balance = true;
    for(i=0; i<p.length(); i++){
        if(p[i] == '(') {
            pair += 1;
            u.push_back('(');
        }
        else {
            pair -= 1;
            u.push_back(')');
        }
        if(pair<0)
            is_balance = false;

        if(pair == 0) {
            i+=1;
            break;
        }
    }
    v = p.substr(i, p.length()-1);
    cout<<p <<" : "<<u<<' '<<v<<'\n';
    if(is_balance)
        return u + make_answer(v);
    else{
        string tmp = "";
        tmp+='(' + make_answer(v) +')';
        for(int i=1; i<u.length()-1; i++){
            if(u[i] == '(')
                tmp+=')';
            else
                tmp+='(';
        }
        return tmp;
    }
}
string solution(string p){
    string answer = "";

    answer = make_answer(p);
    return answer;
}