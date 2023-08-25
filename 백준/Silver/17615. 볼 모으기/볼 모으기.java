import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

class Solve{
    int n;
    String m;

    int makeXYMoveY(List<Integer> yPos){
        int end = n-1;
        int moveCnt = 0;
        for(int i=yPos.size()-1; i>=0; --i){
            if(yPos.get(i) != end) moveCnt += 1;
            end -= 1;
        }
        return moveCnt;
    }

    int makeXYMoveX(List<Integer> xPos){
        int start = 0;
        int moveCnt = 0;
        for(int i=0; i<xPos.size(); ++i){
            if(xPos.get(i) != start) moveCnt += 1;
            start += 1;
        }
        return moveCnt;
    }

    int solve(int _n, String _m){
        n = _n;
        m = _m;
        List<Integer> redPos = new ArrayList<>();
        List<Integer> bluePos = new ArrayList<>();
        for(int i=0; i<n; ++i){
            if(m.charAt(i) == 'R') redPos.add(i);
            else bluePos.add(i);
        }

        int r1 = makeXYMoveX(redPos);
        int r2 = makeXYMoveX(bluePos);
        int r3 = makeXYMoveY(redPos);
        int r4 = makeXYMoveY(bluePos);

        return Math.min(Math.min(r1, r2), Math.min(r3, r4));
    }
}

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String m = br.readLine();

        int answer = new Solve().solve(n, m);

        System.out.println(answer);
    }
}
