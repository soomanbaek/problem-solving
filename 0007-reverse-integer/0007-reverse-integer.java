class Solution {
    public int reverse(int x) {
        // 1. 부호 제거
        boolean minus_flag = false;
        if(x<0){
            x *= -1;
            minus_flag = true;
        }
        // 2. x(int) -> num(string)
        StringBuffer num_sb = new StringBuffer(Integer.toString(x));
        // 3. num(string) reverse
        String num = num_sb.reverse().toString();
        // 4. num(string) -> answer(int)
        try{
            int answer = Integer.parseInt(num);
            // 5. 부호 추가
            if(minus_flag == true){
                answer *= -1;
            }
            return answer;
        }catch(NumberFormatException e){
            return 0;
        }
    }
}