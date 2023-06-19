class Solution {
    public boolean isPalindrome(int x) {
        String num = Integer.toString(x);
        String reverse_num = (new StringBuffer(num)).reverse().toString();
        return num.equals(reverse_num);
    }
}