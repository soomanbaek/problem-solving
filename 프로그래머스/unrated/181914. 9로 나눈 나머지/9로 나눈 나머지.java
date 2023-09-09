import java.util.*;
import java.util.stream.*;

class Solution {
    public int solution(String number) {
        int answer = IntStream.range(0, number.length())
            .map(i -> number.charAt(i) - '0')
            .reduce(0, (acc, num) -> (acc*10 + num)%9);
        return answer;
    }
}