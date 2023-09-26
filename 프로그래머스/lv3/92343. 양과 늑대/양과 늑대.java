import java.util.*;
import java.util.stream.*;

enum ANIMAL{
    SHEEP, WOLF
}

class Node implements Comparable<Node>{
    ANIMAL animal;
    List<Node> childNode;
    int num;
    
    Node(ANIMAL animal, int num){
        this.animal = animal;
        this.num = num;
        childNode = new ArrayList<>();
    }
    void addChild(Node node){
        this.childNode.add(node);
    }
    
    @Override
    public int compareTo(Node node){
        if(this.animal == ANIMAL.SHEEP) return 1;
        else return -1;
    }
}

class Solution {
    int answer = 0;
    Map<Integer, Node> map;
    int N;
    
    void initTree(int[] info, int[][] edges){
        map = new HashMap<>();
        N = info.length;
        for(int i=0; i<N; ++i){
            ANIMAL animal = info[i] == 0 ? ANIMAL.SHEEP : ANIMAL.WOLF;
            
            map.put(i, new Node(animal, i));
        }
        
        for(int[] edge: edges){
            Node parentNode = map.get(edge[0]);
            Node childNode = map.get(edge[1]);
            
            parentNode.addChild(childNode);
        }
    }
    
    void search(Node node, int canVisit, int visited, int sheepNum, int wolfNum){
        visited |= (1 << node.num);
        
        if(node.animal == ANIMAL.SHEEP) sheepNum += 1;
        if(node.animal == ANIMAL.WOLF) wolfNum += 1;
        
        if(sheepNum <= wolfNum) return;
        
        answer = Math.max(answer, sheepNum);
        
        for(Node nextNode: node.childNode){
            canVisit |= (1 << nextNode.num);
        }
        
        for(int i=0; i<N; ++i){
            if((canVisit & (1 << i)) > 0 && (visited & (1 << i)) == 0){
                search(map.get(i), canVisit, visited, sheepNum, wolfNum);
            }
        }
    }
    
    public int solution(int[] info, int[][] edges) {
        initTree(info, edges);
        search(map.get(0), 0, 0, 0, 0);
        return answer;
    }
}