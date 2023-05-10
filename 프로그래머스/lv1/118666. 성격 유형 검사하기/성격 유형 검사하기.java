import java.util.*;

class Solution {
    HashMap<Character, Integer> map;
    void init(){
        map = new HashMap<>();
        map.put('R',0);
        map.put('C',0);
        map.put('J',0);
        map.put('A',0);
    }
    
    void conductSurvey(String[] survey, int[] choices){
        for(int i=0; i<survey.length; ++i){
            String str = survey[i];
            int point = choices[i] - 4;
            if(str.charAt(0)=='R' || str.charAt(0)=='C' || str.charAt(0)=='J' || str.charAt(0)=='A'){
                map.put(str.charAt(0), map.get(str.charAt(0)) + point);
            }else{
                map.put(str.charAt(1), map.get(str.charAt(1)) - point);
            }
        }
    }
    
    String makeAnswer(){
        String answer = 
            (map.get('R') <= 0 ? "R" : "T") +
            (map.get('C') <= 0 ? "C" : "F") +
            (map.get('J') <= 0 ? "J" : "M") +
            (map.get('A') <= 0 ? "A" : "N") ;
        return answer;
    }
    
    public String solution(String[] survey, int[] choices) {
        init();
        conductSurvey(survey, choices);
        
        return makeAnswer();
    }
}