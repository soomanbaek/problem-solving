/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        ListNode answer = new ListNode();
        ListNode cur = answer;

        while(head != null){
            if(head.next != null){
                cur.next = new ListNode(head.next.val);
                cur = cur.next;
            }
            cur.next = new ListNode(head.val);
            cur = cur.next;
            if(head.next == null)   break;
            head = head.next.next;
        }
        return answer.next;
    }
}