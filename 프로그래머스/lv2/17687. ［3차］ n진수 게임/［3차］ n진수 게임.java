import java.util.*;

class Solution {
    int n;
    Map<Character, Integer> map = new HashMap<>();
    void initMap(){
        map.put('0', 0);map.put('1', 1);map.put('2', 2);map.put('3', 3);map.put('4', 4);
        map.put('5', 5);map.put('6', 6);map.put('7', 7);map.put('8', 8);map.put('9', 9);
        map.put('A', 10);map.put('B', 11);map.put('C', 12);map.put('D', 13);map.put('E', 14);map.put('F', 15);
    }
    String increaseNum(String num){
        StringBuilder sb = new StringBuilder(num);
        int carry = 1;
        int idx = 0;
        while(carry > 0){
            if(sb.length() <= idx){
                sb.insert(0, '1');
                break;
            }
            int nn = map.get(sb.charAt(sb.length()-1-idx));
            if(nn + carry >= n){
                sb.setCharAt(sb.length()-1-idx, '0');
            }
            else{
                sb.setCharAt(sb.length()-1-idx, Integer.toHexString(nn+carry).toUpperCase().charAt(0));
                carry = 0;
            }
            idx += 1;
        }
        return sb.toString();
    }
    
    public String solution(int n, int t, int m, int p) {
        this.n = n;
        StringBuilder sb = new StringBuilder();
        initMap();
        String num = "0";
        int idx = 0;
        int turn = 1;
        
        while(sb.length() < t){
            if(idx >= num.length()){
                num = increaseNum(num);
                idx = 0;
            }
            if(turn == p){
                sb.append(num.charAt(idx));
            }
            turn += 1;
            if(turn > m) turn = 1;
            idx += 1;
        }
        
        return sb.toString();
    }
}