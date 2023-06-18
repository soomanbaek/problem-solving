import java.util.*;

class Solution {
    public int solution(int k, int m, int[] _score) {
        Integer[] score = Arrays.stream(_score).boxed().toArray(Integer[]::new);

        int answer = 0;
        Arrays.sort(score, Collections.reverseOrder());

        for(int i=m-1; i<score.length; i+=m){
            answer += score[i] * m;
        }
        return answer;
    }
}