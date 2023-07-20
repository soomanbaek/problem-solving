import java.util.*;

class Solution {
    List<Set<Integer>> winners;
    List<Set<Integer>> losers;
    List<Set<Integer>> accWinner;
    List<Set<Integer>> accLoser;
    boolean[] isUpdated;
    
    void calculateAcc(int num){
        isUpdated[num] = true;
        for(int winner: winners.get(num)){
            if(isUpdated[winner] == false){
                calculateAcc(winner);
            }
            accWinner.get(num).addAll(accWinner.get(winner));
        }
        for(int loser: losers.get(num)){
            if(isUpdated[loser] == false){
                calculateAcc(loser);
            }
            accLoser.get(num).addAll(accLoser.get(loser));
        }
    }
    
    void updateAcc(int n){
        for(int i=1; i<=n; ++i){
            calculateAcc(i);
        }
    }
    
    void show(int n){
        for(int i=1; i<=n; ++i){
            System.out.println(winners.get(i));
        }
    }
    
    void showAcc(int n){
        for(int i=1; i<=n; ++i){
            System.out.println(accWinner.get(i).size() + " " + accLoser.get(i).size());
        }
    }
    
    void updateWinners(int n, int[][]results){
        losers = new ArrayList<>(n+1);
        accLoser = new ArrayList<>(n+1);
        winners = new ArrayList<>(n+1);
        accWinner = new ArrayList<>(n+1);
        isUpdated = new boolean[n+1];
        
        for(int i=0; i<=n; ++i){
            winners.add(new HashSet<>());
            accWinner.add(new HashSet<>());
            accWinner.get(i).add(i);
            
            losers.add(new HashSet<>());
            accLoser.add(new HashSet<>());
            accLoser.get(i).add(i);
        }
        
        for(int[] result: results){
            int winner = result[0];
            int loser = result[1];
            
            winners.get(loser).add(winner);
            losers.get(winner).add(loser);
        }
    }
    public int solution(int n, int[][] results) {
        int answer = 0;
        updateWinners(n, results);
        // show(n);
        updateAcc(n);
        isUpdated = new boolean[n+1];
        updateAcc(n);
        isUpdated = new boolean[n+1];
        updateAcc(n);
        // showAcc(n);
        for(int i=1; i<=n; ++i){
            if(accWinner.get(i).size() + accLoser.get(i).size() == n + 1) answer += 1;
        }
        return answer;
    }
}