class Solution {
    public String solution(int[] foods) {
        String answer = "0";
        for(int i=foods.length-1; i>0; --i){
            int food = foods[i];
            for(int j=0; j<food/2; ++j){
                answer = i + answer + i;
            }
        }
        return answer;
    }
}