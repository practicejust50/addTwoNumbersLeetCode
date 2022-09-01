/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
        ListNode l3 = new ListNode();
        
        ListNode dummy_head = l3;
        
        int carry = 0;
        while (l1 != null || l2 != null || carry != 0) {
            int val1 = l1 != null ? l1.val : 0;
            int val2 = l2 != null ? l2.val : 0;
            
            int sum = val1 + val2 + carry;
            
            carry = sum / 10;
             
            int last_digit = sum % 10;
            
            ListNode new_node = new ListNode(last_digit);
            
            dummy_head.next = new_node;
            
            if (l1 != null) l1 = l1.next;
            if (l2 != null) l2 = l2.next;
            
            dummy_head = dummy_head.next;
        }
        
        return l3.next;
    }
}