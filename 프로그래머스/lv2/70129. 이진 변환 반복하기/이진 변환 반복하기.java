class Solution {
    int[] answer;
    String deleteZero(String s){
        return s.replaceAll("0", "");
    }
    int getZeroNum(String s){
        int zeroNum = 0;
        for(int i=0; i<s.length(); ++i){
            if(s.charAt(i) == '0'){
                zeroNum += 1;
            }
        }
        return zeroNum;
    }
    String binaryTransform(String s){
        int c = s.length();
        StringBuilder sb = new StringBuilder();
        while(c > 0){
            if(c%2 == 0){
                sb.append("0");
            }else{
                sb.append("1");
            }
            c/=2;
        }
        return sb.reverse().toString();
    }
    
    public int[] solution(String s) {
        answer = new int[2];
        
        
        String str = s;
        while(!str.equals("1")){
            int zeroNumBefore = getZeroNum(str);
            str = deleteZero(str);
            int zeroNumAfter = getZeroNum(str);
            str = binaryTransform(str);
            
            answer[0] += 1;
            answer[1] += (zeroNumBefore - zeroNumAfter);
        }
        
        return answer;
    }
}