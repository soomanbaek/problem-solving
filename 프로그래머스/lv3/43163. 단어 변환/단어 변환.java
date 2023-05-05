import java.util.*;

class Word{
    String word;
    int num;
    Word(String word, int num){
        this.word = word;
        this.num = num;
    }
}

class Solution {
    String target;
    String[] word;
    int N;
    boolean[] visited;
    
    boolean isPossibleToChange(String prev, String next){
        int diff_num = 0;
        for(int i=0; i<prev.length(); ++i){
            if(prev.charAt(i) != next.charAt(i)){
                diff_num +=1;
                if(diff_num > 1)    break;
            }
        }
        if(diff_num != 1)   return false;
        return true;
    }
    
    public int solution(String begin, String _target, String[] _word) {
        int answer = 0;
        
        target = _target;
        word = _word;
        N = word.length;
        visited = new boolean[N];
        
        Queue<Word> q = new LinkedList<Word>();
        q.add(new Word(begin, 0));
        
        while(!q.isEmpty()){
            Word cur = q.poll();
            if(cur.word.compareTo(target) == 0){
                answer = cur.num;
                break;
            }
            for(int i=0; i<N; ++i){
                if(visited[i])  continue;
                if(isPossibleToChange(cur.word, word[i])){
                    visited[i] = true;
                    q.add(new Word(word[i], cur.num + 1));
                }
            }
        }
        
        return answer;
    }
}