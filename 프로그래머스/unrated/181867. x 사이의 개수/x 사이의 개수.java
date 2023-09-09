import java.util.*;
import java.util.stream.*;

class Solution {
    public int[] solution(String myString) {
        List<String> strList = new ArrayList<>(Arrays.asList(myString.split("x")));
        
        if(myString.charAt(myString.length()-1) == 'x') strList.add("");
        
        int[] answer = strList.stream().mapToInt(s -> s.length()).toArray();
        return answer;
    }
}