import java.util.*;

class Solution {
    public static ArrayList solution(String[] keymap, String[] targets) {
        ArrayList answer = new ArrayList();
        HashMap<Character, Integer> hm = new HashMap<>();
        for(String key: keymap){
            for(int i=0; i<key.length(); ++i){
                char c = key.charAt(i);
                if(hm.containsKey(c)){
                    if(hm.get(c) > i+1)
                        hm.replace(c, i+1);
                }
                else{
                    hm.put(c, i+1);
                }
            }
        }
        for(String target: targets){
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