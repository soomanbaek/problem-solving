class Solution {
    String[][] romanTable = new String[][]{
        {"I", "IV", "V", "IX"},
        {"X", "XL", "L", "XC"},
        {"C", "CD", "D", "CM"}
    };
    StringBuffer calcToRoman(int num, int idx){
        StringBuffer additionalRoman = new StringBuffer();
        while(num > 0){
            if(num == 9){
                additionalRoman.append(romanTable[idx][3]);
                num -= 9;
            }else if(num >= 5){
                additionalRoman.append(romanTable[idx][2]);
                num -= 5;
            }else if(num == 4){
                additionalRoman.append(romanTable[idx][1]);
                num -= 4;
            }else{
                additionalRoman.append(romanTable[idx][0]);
                num -= 1;
            }
        }
        return additionalRoman;
    }
    public String intToRoman(int num) {
        StringBuffer roman = new StringBuffer();
        
        for(int i=0; i<num/1000; ++i){
            roman.append("M");
        }

        num %= 1000;

        int divide = (int)Math.pow(10, (int)Math.log10(num));
        while(num > 0){
            if(num/divide != 0){
                StringBuffer additionalRoman = calcToRoman(num/divide, (int)Math.log10(num));
                roman.append(additionalRoman);
            }
            num -= num/divide * divide;
            divide /= 10;
        }

        return roman.toString();
    }
}