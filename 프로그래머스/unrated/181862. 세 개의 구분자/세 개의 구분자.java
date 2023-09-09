import java.util.stream.*;
import java.util.*;

class Solution {
    public String[] solution(String myStr) {
        String[] answer = Arrays.stream(myStr.split("[abc]")).filter(str -> str.length() > 0).toArray(String[]::new);
        if(answer.length == 0){
            answer = new String[1];
            answer[0] = "EMPTY";
        }
        return answer;
    }
}