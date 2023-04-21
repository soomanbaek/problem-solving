#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";

    int H,M,S;
    int play_t, adv_t;
    sscanf(play_time.c_str(), "%d:%d:%d", &H, &M, &S);
    play_t = 3600 * H + 60 * M + S;
    sscanf(adv_time.c_str(), "%d:%d:%d", &H, &M, &S);
    adv_t = 3600 * H + 60 * M + S;

    vector<int> start;
    vector<int> end;
    for(auto log : logs){
        int H1, M1, S1, H2, M2, S2;
        sscanf(log.c_str(), "%d:%d:%d-%d:%d:%d", &H1, &M1, &S1, &H2, &M2, &S2);
        start.push_back(3600 * H1 + 60 * M1 + S1);
        end.push_back(3600 * H2 + 60 * M2 + S2);
    }
    vector<long long> total(play_t + 1, 0);

    for(int i = 0; i < logs.size(); i++){
        total[start[i]] += 1;
        total[end[i]] -= 1;
    }
    for(int i = 1; i < play_t; i++){
        total[i] = total[i] + total[i - 1]; //  total_time 재정의
    }

    for(int i = 1; i < play_t; i++)
        total[i] = total[i] + total[i-1];

    int answer_time = 0;
    long long max_time = 0;
    for(int i = 0; i < play_t; i++) {
        long long time;
        if(i >= adv_t) {
            time = total[i] - total[i - adv_t];
        }
        else
            time = total[i];
        if (time > max_time) {
            max_time = time;
            if(i >= adv_t)
                answer_time = i - adv_t + 1;
        }
    }
    answer.push_back(answer_time/36000 + '0');
    answer.push_back((answer_time%36000)/3600 + '0');
    answer.push_back(':');
    answer.push_back((answer_time%3600)/600 + '0');
    answer.push_back((answer_time%600)/60 + '0');
    answer.push_back(':');
    answer.push_back((answer_time%60)/10 + '0');
    answer.push_back((answer_time%10) + '0');

    return answer;
}