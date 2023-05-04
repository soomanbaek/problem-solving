import java.util.*;

class Solution {
    public long solution(long r1, long r2) {
        long answer = 0;
        
        for(long i=0; i<=r2; ++i){
            long h1 = (long)(Math.sqrt(r2*r2 - i*i));
            long h2 = (long)(Math.sqrt(r1*r1 - i*i)-0.0000000001);
            answer += h1 - h2;
        }
        answer *= 4;
        return answer;
    }
}