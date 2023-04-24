#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    sort(tangerine.begin(), tangerine.end());
    vector<int> sameSizeTangerineNum;
    int curSize = tangerine[0];
    int sameSizeNum = 0;
    for(auto &tangerineSize: tangerine){
        if(tangerineSize == curSize){
            sameSizeNum += 1;
            continue;
        }
        sameSizeTangerineNum.push_back(sameSizeNum);
        curSize = tangerineSize;
        sameSizeNum = 1;
    }
    sameSizeTangerineNum.push_back(sameSizeNum);

    sort(sameSizeTangerineNum.rbegin(), sameSizeTangerineNum.rend());

    int idx = 0;
    while(k>0){
        k -= sameSizeTangerineNum[idx++];
    }
    answer = idx;

    return answer;
}