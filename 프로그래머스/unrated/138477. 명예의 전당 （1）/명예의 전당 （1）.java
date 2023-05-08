import java.util.*;

class Solution {
    public List solution(int k, int[] score) {
        List<Integer> answer = new LinkedList<>();
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        
        for(int i=0; i<score.length; ++i){
            pq.add(score[i]);
            if(pq.size() > k) pq.remove();
            answer.add(pq.peek());
        }
        
        return answer;
    }
}