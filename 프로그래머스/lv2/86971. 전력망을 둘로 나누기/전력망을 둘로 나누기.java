import java.util.*;

class Solution {
    List<List<Integer>> D;
    boolean[] visited;
    void init(int n, int[][] wires){
        D = new ArrayList<>(n+1);
        visited = new boolean[n+1];

        for(int i=0; i<=n; ++i) D.add(new LinkedList<>());

        for(int[] wire: wires){
            D.get(wire[0]).add(wire[1]);
            D.get(wire[1]).add(wire[0]);
        }
    }

    int dfs(int node){
        visited[node] = true;
        int sum = 1;
        Iterator<Integer> iter = D.get(node).iterator();
        while(iter.hasNext()){
            Integer next_node = iter.next();
            if(visited[next_node])    continue;
            sum += dfs(next_node);
        }
        return sum;
    }
    public int solution(int n, int[][] wires) {
        init(n, wires);
        int answer = 101;

        for(int[] wire: wires){
            Arrays.fill(visited, false);
            visited[wire[1]] = true;
            int num = dfs(wire[0]);
            answer = Math.min(answer, Math.abs(n-num*2));
        }

        return answer;
    }
}