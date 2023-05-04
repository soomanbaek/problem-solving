import java.util.Stack;

class Node{
    int value;
    Node next;
    Node prev;
    Node(int value){
        this.value = value;
        this.next = null;
        this.prev = null;
    }
}

class LinkedList{
    Node head;
    Node tail;
    LinkedList(){
        head = null;
        tail = null;
    }
    void insertTail(int value){
        Node newNode = new Node(value);
        if(tail == null){
            head = newNode;
            tail = newNode;
            return;
        }
        newNode.prev = tail;
        tail.next = newNode;
        tail = tail.next;
    }
    void deleteThreeNode(Node cur){
        Node nextNode = cur.next.next.next.next;
        Node prevNode = cur.prev;
        if(nextNode != null)
            nextNode.prev = prevNode;
        if(prevNode != null) {
            prevNode.next = nextNode;
        }else{
            head = nextNode;
        }
    }
}
class Solution {
    public int solution(int[] ingredient) {
        int answer = 0;

        LinkedList list = new LinkedList();
        for(int i: ingredient){
            list.insertTail(i);
        }

        Node cur = list.head;
        Stack<Node> stack = new Stack<>();
        while(cur != null){
            if(cur.next != null && cur.next.next != null && cur.next.next.next != null) {
                if (cur.value == 1 && cur.next.value == 2 && cur.next.next.value == 3 && cur.next.next.next.value == 1) {
                    list.deleteThreeNode(cur);
                    if(!stack.isEmpty()){
                        cur = stack.pop();
                    }else{
                        cur = cur.next.next.next.next;
                    }
                    answer += 1;
                }
                else {
                    if(cur.value == 1){
                        stack.push(cur);
                    }
                    cur = cur.next;
                }
            }else
                break;
        }
        return answer;
    }
}