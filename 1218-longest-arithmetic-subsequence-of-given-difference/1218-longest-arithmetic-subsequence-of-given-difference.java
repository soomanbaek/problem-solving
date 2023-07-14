class Solution {
    int minIdx = 0;
    int maxIdx = 20000;
    final int INDEX_OFFSET = 10000;

    public int longestSubsequence(int[] arr, int difference) {
        int[] D = new int[maxIdx+1];

        for(int num: arr){
            int adjustedIdx = num + INDEX_OFFSET;
            int prevIdx = adjustedIdx - difference;
            if(prevIdx < minIdx || prevIdx > maxIdx){
                D[adjustedIdx] = 1;
                continue;
            }
            D[adjustedIdx] = D[prevIdx] + 1;
        }

        int answer = Arrays.stream(D).max().getAsInt();

        return answer;
    }
}