class Solution {
    String[] digitLetters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs","tuv", "wxyz"};

    void makeLetter(List<String> answer, String digits, String str){
        if(digits.length() == 0){
            answer.add(str);
            return;
        }
        int number = Integer.parseInt(digits.substring(0,1));

        digits = digits.substring(1);        
        
        String digitLetter = digitLetters[number];
        for(int i=0; i<digitLetter.length(); ++i){
            makeLetter(answer, digits, str+digitLetter.charAt(i));
        }
    }

    public List<String> letterCombinations(String digits) {
        List<String> answer = new ArrayList<String>();

        if(digits.length() > 0){
            makeLetter(answer, digits, "");
        }

        return answer;
    }
}