class Solution {
    public int solution(String binomial) {
        String[] splitedBinomial = binomial.split(" ");
        int a = Integer.parseInt(splitedBinomial[0]);
        String op = splitedBinomial[1];
        int b = Integer.parseInt(splitedBinomial[2]);
        int answer = 0;
        if(op.equals("+")) answer = a + b;
        if(op.equals("-")) answer = a - b;
        if(op.equals("*")) answer = a * b;
        return answer;
    }
}