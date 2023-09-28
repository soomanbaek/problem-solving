import java.util.*;
import java.util.stream.*;
import java.util.OptionalInt;

class Solution {
    public int solution(int[][] triangle) {
        int N = triangle.length;
        int[][] D = new int[N][N];
        
        int sum = 0;
        for(int i=0; i<N; ++i){
            sum += triangle[i][0];
            D[i][0] = sum;
        }
        
        sum = 0;
        for(int i=0; i<N; ++i){
            int L = triangle[i].length - 1;
            sum += triangle[i][L];
            D[i][L] = sum;
        }
        
        for(int i=1; i<N; ++i){
            for(int j=1; j<triangle[i].length-1; ++j){
                D[i][j] = Math.max(D[i][j], D[i-1][j-1] + triangle[i][j]);
                D[i][j] = Math.max(D[i][j], D[i-1][j] + triangle[i][j]);
            }
        }
        
        int answer = Arrays.stream(D[N-1]).max().getAsInt();
        return answer;
    }
}