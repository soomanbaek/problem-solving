import java.util.*;

class Solution {
    public ArrayList solution(String s) {
        ArrayList answer = new ArrayList();
        HashMap<Character, Integer> hm = new HashMap<Character, Integer>();

        for(int i=0; i<s.length(); ++i){
            char c = s.charAt(i);
            answer.add(i - hm.getOrDefault(c, i+1));
            hm.put(c, i);
        }
        return answer;
    }
}