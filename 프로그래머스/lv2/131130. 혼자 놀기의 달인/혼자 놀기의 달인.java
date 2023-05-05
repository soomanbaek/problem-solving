class Solution {
    int[] cards;
    int num1 = 0;
    int num2 = 0;
    boolean[] isOpen = new boolean[101];
    
    void openBox(int cur_box, int num){
        isOpen[cur_box] = true;
        int next_box = cards[cur_box]-1;
        if(isOpen[next_box]){
            if(num1 < num){  
                num2 = num1;
                num1 = num;
            }
            else if(num2 < num) num2 = num;
        }else{
            openBox(next_box, num+1);
        }
    }
    
    public int solution(int[] _cards) {
        cards = _cards;
        int answer = 0;
        
        for(int i=0; i<cards.length; ++i){
            if(isOpen[i]) continue;
            openBox(i, 1);
        }
        answer = num1 * num2;
        return answer;
    }
}