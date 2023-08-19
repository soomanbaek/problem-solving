class Solution {
    public int solution(String s) {
        int answer = 0;

        char same_c = s.charAt(0);
        int same_num = 0;
        int diff_num = 0;

        for(int i=0; i<s.length(); ++i){
            char c = s.charAt(i);
            if(same_num == 0){
                same_c = c;
                same_num += 1;
                continue;
            }
            if(c == same_c) same_num += 1;
            else diff_num += 1;
            if(same_num == diff_num){
                answer += 1;
                same_num = 0;
                diff_num = 0;
                continue;
            }
        }
        if(same_num > 0)    answer += 1;
        return answer;
    }
}