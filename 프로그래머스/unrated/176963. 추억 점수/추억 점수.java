import java.util.HashMap;

class Solution {
    String[] names;
    int[] yearning;

    HashMap<String, Integer> map = new HashMap<>();

    void makeMap(){
        for(int i=0; i<names.length; ++i){
            String name = names[i];
            int year = yearning[i];

            map.put(name, year);
        }
    }

    public int[] solution(String[] names, int[] yearning, String[][] photoList) {
        int[] answer = new int[photoList.length];
        // init
        this.names = names;
        this.yearning = yearning;
        // mapping
        this.makeMap();

        for(int i=0; i<photoList.length; ++i){
            int score = 0;
            for(String photo: photoList[i]){
                if(map.containsKey(photo))
                    score += map.get(photo);
            }
            answer[i] = score;
        }
        return answer;
    }
}