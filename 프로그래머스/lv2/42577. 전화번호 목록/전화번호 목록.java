import java.util.*;

class Solution {
    public boolean solution(String[] phone_book) {
        Map<String, Boolean> map = new HashMap<>();
        Arrays.sort(phone_book);
        for(String phone: phone_book){
            StringBuilder sb = new StringBuilder();
            for(int i=0; i<phone.length(); ++i){
                sb.append(phone.charAt(i));
                if(map.getOrDefault(sb.toString(), false) == true){
                    return false;
                }
            }
            map.put(phone, true);
        }
        return true;
    }
}