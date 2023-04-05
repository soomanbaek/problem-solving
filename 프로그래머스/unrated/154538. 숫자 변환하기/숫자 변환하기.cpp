#include <string>
#include <vector>
#include <queue>

using namespace std;

bool visited[1000001];

class Num{
public:
    int num;
    int cnt;
    Num(int n, int c){
        this->num = n;
        this->cnt = c;
    }
};

int solution(int x, int y, int n) {
    int answer = -1;
    queue<Num> Q;
    Q.push({x,0});
    visited[x] = true;
    while(!Q.empty()){
        Num cur = Q.front();
        Q.pop();
        if(cur.num == y){
            answer = cur.cnt;
            break;
        }
        if(cur.num + n <= y){
            if(!visited[cur.num + n]){
                visited[cur.num + n] = true;
                Q.push({cur.num + n, cur.cnt + 1});
            }
        }
        if(cur.num * 2 <= y){
            if(!visited[cur.num * 2]){
                visited[cur.num * 2] = true;
                Q.push({cur.num * 2, cur.cnt + 1});
            }
        }
        if(cur.num * 3 <= y){
            if(!visited[cur.num * 3]){
                visited[cur.num * 3] = true;
                Q.push({cur.num * 3, cur.cnt + 1});
            }
        }
    }
    return answer;
}