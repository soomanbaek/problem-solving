import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

class Main{
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    Map<Integer, Integer> startIdx = new HashMap<>();
    Map<Integer, Integer> endIdx = new HashMap<>();

    int n = Integer.parseInt(br.readLine());
    int[] arr = new int[n];

    for(int i=0; i<n; ++i){
      arr[i] = Integer.parseInt(br.readLine());
    }
    int[] sortedArr = Arrays.stream(arr).sorted().toArray();

    int prev = sortedArr[0];

    startIdx.put(prev, 0);
    for(int i=1; i<n; ++i){
      int cur = sortedArr[i];
      if(prev != cur) {
        endIdx.put(prev, i-1);
        startIdx.put(cur, i);
        prev = cur;
      }
    }
    endIdx.put(prev, n-1);

    int answer = 0;
    for(int idx=n-1; idx>=0; --idx){
      int num = arr[idx];
      answer = Integer.max(answer, idx - endIdx.get(num));
    }

    System.out.println(answer + 1);
  }
}