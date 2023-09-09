import java.util.*;
import java.util.stream.*;

class Solution {
    public String solution(String str1, String str2) {
        String answer = IntStream.range(0, str1.length() + str2.length()).mapToObj(i -> i%2 == 0 ? String.valueOf(str1.charAt(i/2)) : String.valueOf(str2.charAt(i/2))).collect(Collectors.joining());
        return answer;
    }
}