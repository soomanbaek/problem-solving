import java.util.*;
import java.lang.String;

class Solution {
    public String solution(String X, String Y) {
        int[] arr1 = new int[10];
        int[] arr2 = new int[10];
        String answer = "";
        for(int i=0; i<X.length(); ++i){
            arr1[X.charAt(i)-'0'] += 1;
        }
        for(int i=0; i<Y.length(); ++i){
            arr2[Y.charAt(i)-'0'] += 1;
        }
        StringBuffer sb = new StringBuffer();
        for(int i=9; i>=0; --i){
            int M = Math.min(arr1[i], arr2[i]);
            for(int j=0; j<M; ++j){
                sb.append(i);
            }
        }
        while(sb.length() > 1 && sb.charAt(0) == '0'){
            sb.deleteCharAt(0);
        }
        answer = sb.toString();
        if(answer.length() == 0)    answer = "-1";
        return answer;
    }
}