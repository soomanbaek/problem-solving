#include <string>
#include <vector>
#include <queue>

using namespace std;

class moveInfo{
public:
    int storey;
    int moveNum;
};

int solution(int storey) {
    int answer = 987654321;
    queue<moveInfo> Q;
    
    Q.push({storey, 0});
    
    while(!Q.empty()){
        moveInfo cur = Q.front();   Q.pop();
        
        while(cur.storey){
            
            int storeyNum = cur.storey%10;
            cur.storey /= 10;
            
            if(storeyNum == 5){
                cur.moveNum += 5;
                Q.push({cur.storey+1, cur.moveNum});
            }else if(storeyNum <5){
                cur.moveNum += storeyNum;
            }else{
                cur.moveNum += (10 - storeyNum);
                cur.storey += 1;
            }
            
            if(cur.storey == 0){
                answer = min(answer, cur.moveNum);
            }
        }
    }
    return answer;
}