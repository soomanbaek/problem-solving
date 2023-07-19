import java.util.*;

class Solution {
    int N;
    Map<String, ArrayList<String>> map = new HashMap<>();
    Map<String, Integer> remainedTicket = new HashMap<>();
    
    String getRoute(String startAirport, String endAirport){
        return startAirport + endAirport;
    }
    
    void init(String[][]tickets){
        N = tickets.length;
        Arrays.sort(tickets, (t1, t2) -> {
            return t1[1].compareTo(t2[1]);
        });
        
        for(String[] ticket: tickets){
            String startAirport = ticket[0];
            String endAirport = ticket[1];
            
            if(!map.containsKey(startAirport)){
                map.put(startAirport, new ArrayList<>());
            }
            String route = getRoute(startAirport, endAirport);
            remainedTicket.put(route, remainedTicket.getOrDefault(route, 0) + 1);
            map.get(startAirport).add(endAirport);
        }
    }
    
    boolean dfs(String curAirport, LinkedList<String> answer, int visitedNum){
        answer.add(curAirport);
        if(visitedNum == N)    return true;
        
        for(String nextAirport: map.getOrDefault(curAirport, new ArrayList<>())){
            String route = getRoute(curAirport, nextAirport);
            
            if(remainedTicket.get(route) == 0) continue;
            
            remainedTicket.replace(route, remainedTicket.get(route) - 1);
            
            if(dfs(nextAirport, answer, visitedNum + 1))
                return true;
            
            remainedTicket.replace(route, remainedTicket.get(route) + 1);
        }
        answer.removeLast();
        return false;
    }
    
    public List<String> solution(String[][] tickets) {
        init(tickets);
        
        LinkedList<String> answer = new LinkedList<String>();
        
        dfs("ICN", answer, 0);
        
        return answer;
    }
}