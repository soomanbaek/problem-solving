import java.util.*;

class Solution {
    public static ArrayList solution(String[] keymap, String[] targets) {
        ArrayList answer = new ArrayList();
        HashMap<Character, Integer> hm = new HashMap<>();
        for(int j=0; j<keymap.length; ++j){
            for(int i=0; i<keymap[j].length(); ++i){
                char c = keymap[j].charAt(i);
                if(hm.containsKey(c) && hm.get(c) < i+1)  continue;
                hm.put(c, i+1);
            }
        }
        for(int j=0; j< targets.length; ++j){
            String target = targets[j];
            int num = 0;
            for(int i=0; i<target.length(); ++i){
                char c = target.charAt(i);
                if(!hm.containsKey(c)){
                    num = -1;
                    break;
                }
                num += hm.get(c);
            }
            answer.add(num);
        }
        return answer;
    }
}