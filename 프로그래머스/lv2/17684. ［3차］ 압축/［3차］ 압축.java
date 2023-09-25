import java.util.*;
import java.util.stream.*;

class Node{
    Map<Character, Node> childNode = new HashMap<>();
    boolean isEndOfWord = false;
    int idx = 0;
}

class Trie{
    Node rootNode = new Node();
    int idx = 1;
    
    void insert(String str){
        Node node = this.rootNode;
        
        for(int i=0; i<str.length(); ++i){
            node = node.childNode.computeIfAbsent(str.charAt(i), key -> new Node());
        }
        node.isEndOfWord = true;
        node.idx = this.idx++;
    }
}

class Solution {
    Trie trie;
    List<Integer> answer = new ArrayList<>();
    
    void initTrie(){
        trie = new Trie();
        for(char ch = 'A'; ch <= 'Z'; ch ++){
            trie.insert(Character.toString(ch));
        }
    }
    
    String getW(String str){
        Node node = trie.rootNode;
        String w = "";
        int idx = 0;
        
        int i=0;
        while((i < str.length()) && node.childNode.containsKey(str.charAt(i))){
            node = node.childNode.get(str.charAt(i));
            w += str.charAt(i);
            idx = node.idx;
            i += 1;
        }
        
        answer.add(idx);
        return w;
    }
    
    public List<Integer> solution(String msg) {
        initTrie();
        
        int i=0;
        while(i < msg.length()){
            String w = getW(msg.substring(i));
            i += w.length();
            if(i < msg.length()){
                trie.insert(w + msg.charAt(i));
            }
        }
        
        return answer;
    }
}