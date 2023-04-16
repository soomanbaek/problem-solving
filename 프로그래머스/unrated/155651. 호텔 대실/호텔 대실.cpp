#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int convertToSec(string time, int carry = 0){
    int min = 0;
    min += (time[0] - '0')*10*60;
    min += (time[1] - '0')*60;
    min += (time[3] - '0')*10;
    min += (time[4] - '0');
    
    return min + carry;
} 

class HotelUseInfo{
public:
    int min;
    bool isEnter;
    HotelUseInfo(int m, int e){
        this -> min = m;
        this -> isEnter = e;
    };
};

struct compare{
    bool operator()(HotelUseInfo& a, HotelUseInfo& b){
        if(a.min == b.min)  
            return a.isEnter > b.isEnter;
        return a.min > b.min;
    }
};

int solution(vector<vector<string>> book_time_list) {
    int answer = 0;
    priority_queue<HotelUseInfo, vector<HotelUseInfo>, compare> PQ;
    for(auto& book_time: book_time_list){
        PQ.push({convertToSec(book_time[0]), true});
        PQ.push({convertToSec(book_time[1], 10), false});
    }
    
    int room_num = 0;
    while(!PQ.empty()){
        HotelUseInfo hotelUseInfo = PQ.top();
        PQ.pop();
        
        if(hotelUseInfo.isEnter){
            room_num += 1;
            answer = max(answer, room_num);
        }
        else{
            room_num -= 1;
        }
    }
    return answer;
}