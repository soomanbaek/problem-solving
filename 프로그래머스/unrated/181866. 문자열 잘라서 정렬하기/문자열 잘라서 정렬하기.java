import java.util.*;
import java.util.stream.*;

class Solution {
    public String[] solution(String myString) {
        String[] answer = Arrays.stream(myString.split("x"))
            .filter(s -> s.length() != 0)
            .sorted()
            .toArray(String[]::new);
        return answer;
    }
}