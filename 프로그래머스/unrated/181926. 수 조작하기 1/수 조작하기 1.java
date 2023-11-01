class Solution {
    int getPoint(int command){
        if(command == 'w') return 1;
        if(command == 's') return -1;
        if(command == 'd') return 10;
        if(command == 'a') return -10;
        return 0;
    }
    
    public int solution(int n, String control) {
        int answer = n;
        for(char command : control.toCharArray()){
            answer += getPoint(command);
        }
        
        return answer;
    }
}