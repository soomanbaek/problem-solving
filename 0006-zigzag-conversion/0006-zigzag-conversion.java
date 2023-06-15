class Solution {
    public String convert(String s, int numRows) {
        if(numRows == 1) return s; // numRows가 1이면 그 자체를 반환

        StringBuffer sb = new StringBuffer();
        int d = numRows*2-2;
        int zigzag_d = d;
        for(int i=0; i<numRows; ++i){
            int j = 0;
            while(i + j*d < s.length()){
                int idx = i + j*d;
                sb.append(s.charAt(idx));
                // 지그재그 문자가 존재하는 문자열의 경우
                if(0 < i && i < numRows-1){ 
                    int zigzag_idx = idx + zigzag_d;
                    if(zigzag_idx < s.length()){
                        sb.append(s.charAt(zigzag_idx));
                    }
                }
                ++j;
            }
            zigzag_d -= 2;
        }
        String convertedString = sb.toString();
        
        return convertedString;
    }
}