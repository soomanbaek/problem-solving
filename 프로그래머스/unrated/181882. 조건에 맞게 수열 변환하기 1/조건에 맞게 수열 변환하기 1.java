import java.util.*;
import java.util.stream.*;

class Solution {
    public int[] solution(int[] arr) {
        return Arrays.stream(arr).map(num -> {
            if(num >= 50 && num % 2 == 0) return num/2;
            if(num < 50 && num % 2 == 1) return num*2;
            return num;
        }).toArray();
    }
}