import java.util.*;

class Solution {
  int N;
  HashMap<String, Integer> id;
  ArrayList<HashSet<Integer>> reportUser;
  int[] receivedMessageNum;

  void init(String[] id_list){
    N = id_list.length;
    id = new HashMap<>();
    reportUser = new ArrayList<>();
    receivedMessageNum = new int[N+1];
	for(int i=0; i<=N; ++i){
        HashSet<Integer> _set = new HashSet<Integer>();
        reportUser.add(_set);
    }
    makeId(id_list);
  }

  void makeId(String[] id_list){
    int num = 1;
    for(String _id: id_list){
      id.put(_id, num++);
    }
  }

  void postMessage(int id){
    for (Integer integer : reportUser.get(id)) {
      receivedMessageNum[integer]++;
    }
  }

  public int[] solution(String[] id_list, String[] reports, int k) {
    init(id_list);
    int[] answer = new int[N];

    for(String report: reports){
      String reporter = report.split(" ")[0];
      String reported = report.split(" ")[1];
      int reporterId = id.get(reporter);
      int reportedId = id.get(reported);

       reportUser.get(reportedId).add(reporterId);
    }

     for(int id=1; id<=N; ++id){
         if(reportUser.get(id).size() >= k){
             postMessage(id);
         }
     }

    for(int i=0; i<N; ++i){
        answer[i] = receivedMessageNum[i+1];
    }
    return answer;
  }
}