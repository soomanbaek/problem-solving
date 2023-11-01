import java.util.*;
import java.util.stream.*;

class Solution {
    public int solution(int[] num_list) {
        int mul = Arrays.stream(num_list).reduce(1, (ret, num) -> ret * num);
        int sum = Arrays.stream(num_list).sum();
        return mul < sum*sum ? 1 : 0;
    }
}