import java.util.*;
import java.util.stream.*;

class Solution {
    public String solution(String my_string, int[] index_list) {
        String answer = Arrays.stream(index_list).mapToObj(i -> String.valueOf(my_string.charAt(i))).collect(Collectors.joining());
        return answer;
    }
}