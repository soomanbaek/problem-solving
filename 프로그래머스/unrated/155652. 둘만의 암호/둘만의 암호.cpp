#include <string>
#include <vector>

using namespace std;

bool isSkip[26];
string solution(string s, string skip, int index) {
    string answer = "";
    
    for(int i=0; i<skip.length(); ++i){
        isSkip[skip[i]-'a'] = true;
    }
    
    for(int i=0; i<s.length(); ++i){
        int n = index;
        while(n){
            if(s[i] == 'z') s[i] = 'a';
            else s[i] += 1;
            
            if(isSkip[s[i]-'a']){
                continue;
            }
            n -= 1;
        }
    }
    answer = s;
    return answer;
}