import java.util.*;

class Solution {
    int n;
    int[] weak;
    int[] dist;
    
    int checkOuterWall(int node, int checked, int num){
        int end = weak[node] + dist[num];
        // 점검 돌기
        for(int i=node; i<weak.length; ++i){
            if(end < weak[i]) break;
            if((checked & (1<<i)) > 0) break;
            checked |= (1<<i);
        }
        // 친구의 점검 거리가 한바퀴를 전부 돌 경우
        if(end >= n){
            end = end % n;
            for(int i=0; i<weak.length; ++i){
                if(end < weak[i]) break;
                if((checked & (1<<i)) > 0) break;
                checked |= (1<<i);
            }
        }
        return checked;
    }
    
    int explore(int node, int checked, int num){
        // 1. 외벽 점검
        checked = checkOuterWall(node, checked, num);
        // 2. 모든 외벽이 전부 점검되었는지 확인 -> 모든 외벽이 점검되었으면 num 반환
        if(checked == ((1<<weak.length)-1)){
            return num + 1;
        }
        // 3. 친구들을 모두 투입했는데 취약 지점 점검하지 못하는 경우
        if(num+1 == dist.length){
            return 10;
        }
        // 4. 다른 친구 투입
        int ret = 10;
        for(int i=0; i<weak.length; ++i){
            if((checked & (1<<i)) != 0){
                continue;
            }
            ret = Math.min(ret, explore(i, checked, num+1));
        }
        
        return ret;
    }
    
    public int solution(int _n, int[] _weak, int[] _dist) {
        int answer = 10;
        n = _n;
        weak = _weak;
        dist = _dist;
        
        dist = Arrays.stream(dist)
            .boxed().sorted(Collections.reverseOrder())
            .mapToInt(Integer::intValue).toArray();
        
        for(int i=0; i<weak.length; ++i){
						answer = Math.min(answer, explore(i, 0, 0));
        }
        if(answer == 10)    answer = -1;
        
        return answer;
    }
}