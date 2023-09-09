import java.util.stream.*;
import java.util.*;

class Solution {
    public String solution(String my_string, int m, int c) {
        String answer = IntStream.range(0, my_string.length())
            .filter(i -> (i+1-c)%m == 0)
            .mapToObj(i -> String.valueOf(my_string.charAt(i)))
            .collect(Collectors.joining());
        
        return answer;
    }
}