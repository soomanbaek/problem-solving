import java.util.*;
import java.util.stream.*;

class Solution {
    public String solution(String[] str_list, String ex) {
        String answer = Arrays.stream(str_list).filter(s -> !s.contains(ex)).collect(Collectors.joining());
        return answer;
    }
}