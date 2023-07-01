class Solution {

    int answer = 987654321;
    int[] cookies;
    int N;
    int k;
    int allUsed;
    
    void distribute(int child, int maxNum, int curNum, int used){
        maxNum = Math.max(maxNum, curNum);
        if(maxNum >= answer)    return;

        if(used == allUsed){
            answer = Math.min(answer, maxNum);
            return;
        }

        if(child < k-1){
            distribute(child+1, maxNum, 0, used);
        }

        for(int i=0; i<N; ++i){
            if((used & (1 << i)) > 0)   continue;
            distribute(child, maxNum, curNum + cookies[i], used|(1<<i));
        }
    }
    public int distributeCookies(int[] _cookies, int _k) {
        cookies = _cookies;
        N = cookies.length;
        k = _k;
        allUsed = (int)Math.pow(2, N) - 1;

        distribute(0, 0, 0, 0);

        return answer;
    }
}