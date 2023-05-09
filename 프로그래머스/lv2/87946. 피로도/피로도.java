// O(N!) : (1 <= N <= 8)
// DFS
import java.util.*;

class Solution {
    int max_num;
    int dungeon_num;
    int[][] dungeons;
    void dfs(int k, int visited, int N){
        boolean is_explore = false;
        for(int i=0; i<dungeon_num; ++i){
            if((visited & (1<<i)) >= 1)    continue;
            if(dungeons[i][0] > k)  continue;
            
            is_explore = true;
            dfs(k-dungeons[i][1], visited | (1<<i), N+1);
        }
        if(!is_explore) max_num = Math.max(max_num, N);
    }
    public int solution(int k, int[][] _dungeons) {
        // init
        int answer = 0;
        dungeons = _dungeons;
        dungeon_num = dungeons.length;
        max_num = 0;
        
        dfs(k, 0, 0);
        
        answer = max_num;
        return answer;
    }
}