import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Solve{
    int r, c, k;
    int[] dr = {-1, 0, 0, 1};
    int[] dc = {0, -1, 1, 0};

    char[][] board;

    int explore(int cur_r, int cur_c, int cnt, boolean[][] visited){
        if(cnt > k) return 0;

        if(cur_r == 0 && cur_c == c-1){
            if(cnt == k) return 1;
            return 0;
        }

        int ret = 0;

        for(int d=0; d<4; ++d){
            int next_r = cur_r + dr[d];
            int next_c = cur_c + dc[d];

            if(next_r < 0 || next_r >= r || next_c < 0 || next_c >= c) continue;
            if(board[next_r][next_c] == 'T') continue;
            if(visited[next_r][next_c]) continue;

            visited[next_r][next_c] = true;
            ret += explore(next_r, next_c, cnt+1, visited);
            visited[next_r][next_c] = false;
        }
        return ret;
    }

    int solve(int _r, int _c, int _k, char[][] _board){
        r = _r; c = _c; k = _k; board = _board;

        boolean[][] visited = new boolean[r][c];
        visited[r-1][0] = true;

        return explore(r-1, 0, 1, visited);
    }
}

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int r = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        char[][] board = new char[r][c];

        for(int i=0; i<r; ++i){
            board[i] = br.readLine().toCharArray();
        }

        int answer = new Solve().solve(r, c, k, board);

        System.out.println(answer);
    }
}
