#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <math.h>
#include <map>
#include <algorithm>

using namespace std;

class ParkInfo{
public:
    int number;
    int enter_time;
    int exit_time;
    
    ParkInfo(string n, string enter_time, string exit_time){
        this->number = stoi(n);
        this->enter_time = this->transTime(enter_time);
        this->exit_time = this->transTime(exit_time);
    }
    
    void setExitTime(string exit_time){
        this->exit_time = this->transTime(exit_time);
    }
    
    int transTime(string time){
        char* hour = strtok((char*)time.c_str(), ":");
        char* minute = strtok(NULL, ":");
        return stoi(hour)*60 + stoi(minute);
    }
};

vector<string> split(string str, string split){
    vector<string> ret;
    char* c = strtok((char*)str.c_str(), split.c_str());
    while(c){
        ret.push_back(c);
        c = strtok(NULL, split.c_str());
    }
    return ret;
}

int clacFee(int parking_time, int base_time, int base_fee, int add_time, int add_fee){
    if(parking_time <= base_time) return base_fee;

    return base_fee + ceil((parking_time-base_time)/(double)add_time) * add_fee;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    // map 사용하면 더 좋음
    // map<int, pair<int,int>> park_infos;
    vector<ParkInfo> park_infos;
    map<string, int> park_info_map;
    map<int, int> park_info_fee;
    
    for(auto& record_string: records){
        vector<string> record = split(record_string, " ");
        if(record[2] == "IN"){
            park_info_map[record[1]] = park_infos.size();
            park_infos.push_back({record[1], record[0], "23:59"});
        }else{
            park_infos[park_info_map[record[1]]].setExitTime(record[0]);
        }
    }
    for(auto park_info: park_infos){
        park_info_fee[park_info.number] += park_info.exit_time - park_info.enter_time;
    }
    
    map<int,int>::iterator iter;
    for(iter=park_info_fee.begin(); iter!=park_info_fee.end(); ++iter){
        answer.push_back(clacFee(iter->second, fees[0], fees[1], fees[2], fees[3]));
    }
    return answer;
}