class Solution {
    boolean[] visited;
    int n;
    int[][] computers;
    
    void dfs(int node){
        visited[node] = true;
        for(int i=0; i<n; ++i){
            if(visited[i]) continue;
            if(computers[node][i] == 0) continue;
            dfs(i);
        }
    }
    public int solution(int _n, int[][] _computers) {
        n = _n;     computers = _computers;
        visited = new boolean[n];
        int answer = 0;
        
        for(int i=0; i<n; ++i){
            if(visited[i])  continue;
            answer+=1;
            dfs(i);
        }
        return answer;
    }
}