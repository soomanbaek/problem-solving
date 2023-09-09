import java.util.stream.*;
import java.util.*;

class Solution {
    public String solution(String my_string, int[] indices) {
        String[] str = my_string.split("");
        for(int idx: indices){
            str[idx] = "";
        }
        String answer = "";
        for(String s: str){
            answer += s;
        }
        return answer;
    }
}