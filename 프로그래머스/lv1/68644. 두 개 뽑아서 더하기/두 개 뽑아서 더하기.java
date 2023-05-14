import java.util.*;

class Solution {
    public List<Integer> solution(int[] numbers) {
        List<Integer> answer = new ArrayList<Integer>();
        HashSet<Integer> hs = new HashSet<>();
        
        for(int i=0; i<numbers.length; ++i){
            for(int j=i+1; j<numbers.length; ++j){
                hs.add(numbers[i]+numbers[j]);
            }
        }
        Iterator<Integer> it = hs.iterator();
        while(it.hasNext()){
            answer.add(it.next());
        }
        Collections.sort(answer);
        return answer;
    }
}