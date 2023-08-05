#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s){
    int answer = 1000;

    if(s.length() ==1 )
        return 1;
    for(int compress = 1; compress <= s.size()/2; compress++){
        int length = s.length();
        string pre ="";
        int cnt = 0;
        for(int i = 0; i < s.length(); i += compress){
            string cur = s.substr(i, compress);
            if(pre == cur)
                cnt++;
            if(pre != cur || i == s.length()-compress){
                if(cnt>0) {
                    length -= cnt * compress;
                    int num = 0;
                    cnt+=1;
                    while(cnt){
                        num+=1;
                        cnt/=10;
                    }
                    length += num;
                }
                pre = cur;
                cnt = 0;
            }
        }
        answer = min(answer,length);
    }

    return answer;
}