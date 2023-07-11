class Solution {
    int[][] D = new int[101][101];
    public int uniquePaths(int m, int n) {
        for(int i=1; i<=m; ++i){
            D[i][1] = 1;
            for(int j=2; j<=n; ++j){
                D[i][j] = D[i-1][j] + D[i][j-1];
            }
        }
        return D[m][n];
    }
}