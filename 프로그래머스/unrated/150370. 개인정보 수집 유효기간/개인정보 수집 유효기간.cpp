#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

class Info{
public:
    int date;
    string person;
    
    Info(int date, string person){
        this->date = date;
        this->person = person;
    }
};

struct compare{
    bool operator()(const Info& l, const Info& r) const{
        return l.date < r.date;
    }
};

vector<string> split(string str, string divide){
    vector<string> ret;
    char* c = strtok((char*)str.c_str(), divide.c_str());
    while(c){
        ret.push_back(c);
        c = strtok(NULL, divide.c_str());
    }
    return ret;
}

int calcDate(string year, string month, string date){
    int ret = stoi(year)*12*28 + stoi(month)*28 + stoi(date);
    
    return ret;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<string, int> M;
    
    vector<string> S = split(today,".");
    int today_date = calcDate(S[0], S[1], S[2]);
    
    for(int i=0; i<terms.size(); ++i){
        vector SS = split(terms[i], " ");
        M.insert({SS[0], stoi(SS[1])*28});
    }
    
    for(int i=0; i<privacies.size(); ++i){
        // privacy 파싱
        vector<string> S1 = split(privacies[i], " ");
        string person = S1[1];
        vector<string> S2 = split(S1[0], ".");
        int date = calcDate(S2[0], S2[1], S2[2]) + M[person];
        if(date <= today_date)  answer.push_back(i+1);
    }
    
    return answer;
}