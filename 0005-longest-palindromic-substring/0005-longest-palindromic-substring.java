class Solution {
    String extractPalindrome(String s, int left, int right){
        while(0<=left && right<s.length()){
            if(s.charAt(left) != s.charAt(right)){
                return s.substring(left+1, right);
            }
            left -= 1;
            right += 1;
        }
        return s.substring(left+1, right);
    }
    
    public String longestPalindrome(String s) {
        String answer = "";
        for(int i=0; i<s.length(); ++i){
            String p1 = extractPalindrome(s, i, i);
            String p2 = extractPalindrome(s, i, i+1);
            if(p1.length() > answer.length()){
                answer = p1;
            }
            if(p2.length() > answer.length()){
                answer = p2;
            }
        }
        return answer;
    }
}