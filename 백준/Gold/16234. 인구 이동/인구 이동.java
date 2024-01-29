import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Node{
    int r;
    int c;
    Node(int r, int c){
        this.r = r;
        this.c = c;
    }
}
class Solve {
    int[] dr = {-1, 0, 0, 1};
    int[] dc = {0, -1, 1, 0};
    int N, L, R;
    int[][] board;

    void markBorderLineOpenCountries(int r, int c, int mark, int[][] countries, boolean[][] visited){
        visited[r][c] = true;
        for(int d=0; d<4; ++d){
            int nr = r + dr[d];
            int nc = c + dc[d];

            if(nr<0 || nr>=N || nc<0 || nc>=N) continue;
            if(visited[nr][nc]) continue;
            int diff = Math.abs(board[r][c] - board[nr][nc]);
            if((L > diff) || (diff > R)) continue;
            countries[r][c] = mark;
            countries[nr][nc] = mark;

            markBorderLineOpenCountries(nr, nc, mark, countries, visited);
        }
    }

    int[][] initBoarderLineOpenCountries(){
        int[][] countries = new int[N][N];
        boolean[][] visited = new boolean[N][N];
        int mark = 1;
        for(int r=0; r<N; ++r){
            for(int c=0; c<N; ++c){
                if(visited[r][c]) continue;
                markBorderLineOpenCountries(r, c, mark, countries, visited);
                mark += 1;
            }
        }
        return countries;
    }

    int getPeopleSum(int r, int c, int mark, int[][] countries, Stack<Node> stack, boolean[][] visited){
        visited[r][c] = true;
        stack.add(new Node(r, c));
        int sum = board[r][c];

        for(int d=0; d<4; ++d){
            int nr = r + dr[d];
            int nc = c + dc[d];
            if(nr<0 || nr>=N || nc<0 || nc>=N) continue;
            if(visited[nr][nc]) continue;
            if(countries[nr][nc] != mark) continue;

            sum += getPeopleSum(nr, nc, mark, countries, stack, visited);
        }
        return sum;
    }

    boolean move(){
        boolean isMoved = false;

        // 1. boarderLineOpenCountries 배열 생성
        int[][] boarderLineOpenCountries = initBoarderLineOpenCountries();

        // 2. 열려있는 경우 인구 이동 시작
        boolean[][] visited = new boolean[N][N];
        for(int r=0; r<N; ++r){
            for(int c=0; c<N; ++c){
                if(visited[r][c]) continue;
                if(boarderLineOpenCountries[r][c] == 0) continue;
                int mark = boarderLineOpenCountries[r][c];

                isMoved = true;
                Stack<Node> stack = new Stack<>();
                int sum = getPeopleSum(r, c, mark, boarderLineOpenCountries, stack, visited);

                int num = sum/stack.size();
                while(!stack.isEmpty()){
                    Node node = stack.peek(); stack.pop();
                    board[node.r][node.c] = num;
                }
            }
        }
        return isMoved;
    }

    void showBoard(int[][] board){
        for(int r=0; r<N; ++r){
            for(int c=0; c<N; ++c){
                System.out.print(board[r][c] + " ");
            }
            System.out.println();
        }
    }
    void solve(int N, int L, int R, int[][] board){
        this.N = N; this.L = L; this.R = R; this.board = board;

        int answer = 0;

        while (move())  answer += 1;

        System.out.println(answer);
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int L = Integer.parseInt(st.nextToken());
        int R = Integer.parseInt(st.nextToken());

        int[][] board = new int[N][N];
        for(int r=0; r<N; ++r){
            st = new StringTokenizer(br.readLine());
            for(int c=0; c<N; ++c){
                board[r][c] = Integer.parseInt(st.nextToken());
            }
        }

        new Solve().solve(N, L, R, board);
    }
}
