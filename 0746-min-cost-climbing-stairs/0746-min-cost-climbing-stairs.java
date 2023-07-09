class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int N = cost.length;
        int[] D = new int[N];

        D[0] = cost[0];
        D[1] = cost[1];
        for(int i=2; i<N; ++i){
            D[i] = Math.min(D[i-2], D[i-1]) + cost[i];
        }
        return Math.min(D[N-1], D[N-2]);
    }
}