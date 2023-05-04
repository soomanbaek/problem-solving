import java.util.*;

class Solution {
    public int solution(int k, int m, int[] _score) {
        Integer[] score = Arrays.stream(_score).boxed().toArray(Integer[]::new);

        int answer = 0;
        Arrays.sort(score, Collections.reverseOrder());

        int num = 0;
        for(int s: score){
            num += 1;
            if(num == m){
                answer += s * m;
                num = 0;
            }
        }
        return answer;
    }
}