import java.util.*;
import java.util.stream.*;

class Util{
    public static String[] splitFileName(String name){
        String[] splitedFileName = {"", "", ""};
        StringBuilder sb = new StringBuilder();
        int flag = 0;
        for(int i=0; i<name.length(); ++i){
            if(flag == 0){ // head
                if('0' <= name.charAt(i) && name.charAt(i) <= '9'){
                    splitedFileName[0] = sb.toString();
                    sb.setLength(0);
                    i -= 1; flag ++; continue;
                }
                sb.append(name.charAt(i));
            }else if(flag == 1){ // number
                if(name.charAt(i) < '0' || '9' < name.charAt(i) || sb.length() >= 5){
                    splitedFileName[1] = sb.toString();
                    sb.setLength(0);
                    i -= 1; flag ++; continue;
                }
                sb.append(name.charAt(i));
            }else{ //tail
                splitedFileName[2] = name.substring(i);
                break;
            }
        }
        if(flag == 1){
            splitedFileName[1] = sb.toString();
        }
        return splitedFileName;
    }
}
class FileName{
    String head;
    String number;
    String tail;
    
    FileName(String name){
        String[] splitedFileName = Util.splitFileName(name);
        this.head = splitedFileName[0];
        this.number = splitedFileName[1];
        this.tail = splitedFileName[2];
    }
    String getName(){
        return head + number + tail;
    }
}

class Solution {
    public List<String> solution(String[] files) {
        List<FileName> fileNames = new ArrayList<>();
        for(String file: files){
            fileNames.add(new FileName(file));
        }
        List<String> answer = fileNames.stream()
            .sorted((f1, f2) -> Integer.parseInt(f1.number) - Integer.parseInt(f2.number))
            .sorted((f1, f2) -> f1.head.toUpperCase().compareTo(f2.head.toUpperCase()))
            .map(FileName::getName)
            .collect(Collectors.toList());
        return answer;
    }
}