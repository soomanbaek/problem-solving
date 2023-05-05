import java.util.*;

class Solution {
    HashMap<String, Integer> map;

    void init(String[] want, int[] number){
        map = new HashMap<>();
        for(int i=0; i<want.length; ++i){
            map.put(want[i], number[i]);
        }
    }

    void traversal_search_10(String[] discount){
        for(int i=0; i<10; ++i){
            if(map.containsKey(discount[i])){
                map.replace(discount[i], map.get(discount[i])-1);
            }
        }
    }

    boolean checkSignUp(){
        Iterator<String> keys = map.keySet().iterator();
        boolean isSignUp = true;
        while(keys.hasNext()){
            if(map.get(keys.next()) > 0)   isSignUp = false;
        }
        return isSignUp;
    }
    public int solution(String[] want, int[] number, String[] discount) {
        int answer = 0;
        this.init(want, number);
        this.traversal_search_10(discount);
        if(checkSignUp())   answer += 1;

        int S = 0;    int E = 10;
        while(E < discount.length){
            if(map.containsKey(discount[S])) map.replace(discount[S], map.get(discount[S])+1);
            if(map.containsKey(discount[E])) map.replace(discount[E], map.get(discount[E])-1);
            if(checkSignUp())   answer += 1;
            ++S; ++E;
        }
        return answer;
    }
}