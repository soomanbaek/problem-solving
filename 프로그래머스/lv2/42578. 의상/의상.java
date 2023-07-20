import java.util.*;

class Solution {
    Map<String, Integer> map;
    
    public int solution(String[][] clothes) {
        int answer = 1;
        map = new HashMap<>();
        
        for(String[] cloth: clothes){
            String category = cloth[1];
            map.put(category, map.getOrDefault(category, 0)+1);
        }
        
        Set<String> categories = map.keySet();
        Iterator<String> iter = categories.iterator();
        while(iter.hasNext()){
            answer *= (map.get(iter.next()) + 1);
        }
        
        
        return answer - 1;
    }
}