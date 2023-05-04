class Solution {
    public int solution(String t, String p) {
        int answer = 0;
        int M = t.length();
        int N = p.length();
        long ip = Long.parseLong(p);

        for(int i=0; i<=M-N; ++i){
            if(Long.parseLong(t.substring(i, i+N)) <= ip) answer += 1;
        }
        return answer;
    }
}