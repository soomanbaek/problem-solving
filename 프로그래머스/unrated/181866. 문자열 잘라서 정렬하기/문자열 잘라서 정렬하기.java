import java.util.*;
import java.util.stream.*;

class Solution {
    public String[] solution(String myString) {
        String[] answer = myString.split("x");
        Arrays.sort(answer, new Comparator<String>(){
            @Override
            public int compare(String a, String b){
                return a.compareTo(b);
            }
        });
        answer = Arrays.stream(answer).filter(s -> s.length() != 0).toArray(String[]::new);
        return answer;
    }
}