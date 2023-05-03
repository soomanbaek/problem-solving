import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.next();

        for(int i=0; i<str.length(); ++i){
            char s = str.charAt(i);
            if('a' <= s && s <= 'z')
                s += 'A'-'a';
            else
                s -= 'A'-'a';
            System.out.print(s);
        }
    }
}