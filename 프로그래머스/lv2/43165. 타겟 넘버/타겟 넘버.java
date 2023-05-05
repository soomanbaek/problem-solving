class Solution {
    int answer = 0;
    int[] numbers;
    int target;
    
    void dfs(int sum, int n){
        if(n == numbers.length){
            if(sum == target){
                answer += 1;
            }
            return;
        }
        dfs(sum + numbers[n], n+1);
        dfs(sum - numbers[n], n+1);
    }
    public int solution(int[] _numbers, int _target) {
        numbers = _numbers;
        target = _target;
        
        dfs(0, 0);
        return answer;
    }
}