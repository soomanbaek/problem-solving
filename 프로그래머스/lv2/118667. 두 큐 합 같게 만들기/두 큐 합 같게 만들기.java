import java.util.*;

class Solution {
    public int solution(int[] queue1, int[] queue2) {
        Queue<Integer> q1 = new LinkedList<>();
        Queue<Integer> q2 = new LinkedList<>();
        long sum1 = 0;
        long sum2 = 0;
        
        for(int val: queue1){ 
            q1.add(val);
            sum1 += val;
        }
        for(int val: queue2){
            q2.add(val);
            sum2 += val;
        }
        
        long total = sum1 + sum2;
        int N = queue1.length + queue2.length;
        
        if(total % 2 == 1)  return -1;
        
        int answer = 0;
        while(sum1 != sum2 && answer <= N*2){
            if(sum1 > total/2){
                int val = q1.poll();
                sum1 -= val;
                sum2 += val;
                q2.add(val);
            }else{
                int val = q2.poll();
                sum1 += val;
                sum2 -= val;
                q1.add(val);
            }
            answer += 1;
        }
        if(answer > N*2) answer = -1;
        
        return answer;
    }
}