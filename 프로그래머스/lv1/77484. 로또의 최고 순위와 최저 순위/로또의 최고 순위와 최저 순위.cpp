#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums){
    int zero = 0;
    int same = 0;
    vector<int> answer;

    sort(win_nums.begin(), win_nums.end());

    for(auto l : lottos){
        if(l == 0) {
            zero += 1;
            continue;
        }
        int index = lower_bound(win_nums.begin(), win_nums.end(), l) - win_nums.begin();

        if(index<6 && win_nums[index] == l)
            same+=1;
    }
    int rank = 7-same - zero;
    answer.push_back(rank <= 6? rank:6);
    answer.push_back(7-same<=6?7-same:6);
    return answer;
}