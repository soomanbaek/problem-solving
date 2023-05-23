import java.util.*;

class Solution {
    HashMap<Integer, Integer> map = new HashMap<>();
    
    void makeMap(int num, int cnt){
        if(num == 55555)    return; // UUUUU까지 올 때 끝냄 (break point)
        
        if(num/10000 == 0){
            num*=10;
            num+=1;
        }else{
            num+=1;
            while(num%10 == 6){
                num /= 10;
                num += 1;
            }
        }
        map.put(num, cnt);
        makeMap(num, cnt+1);
    }
    
    int transWordToNum(String word){
        int num = 0;
        for(int i=0; i<word.length(); ++i){
            num*=10;
            if(word.charAt(i) == 'A')  num += 1;
            else if(word.charAt(i) == 'E') num += 2;
            else if(word.charAt(i) == 'I') num += 3;
            else if(word.charAt(i) == 'O') num += 4;
            else if(word.charAt(i) == 'U') num += 5;
            
        }
        return num;
    }
    public int solution(String word) {
        int answer = 0;
        makeMap(0, 1);
        
        int num = transWordToNum(word);
        
        answer = map.get(num);
        return answer;
    }
}