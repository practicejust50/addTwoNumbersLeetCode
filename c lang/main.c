/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* createNode(int val) {
    struct ListNode* new_node = malloc(sizeof(struct ListNode));
    new_node->val = val;
    new_node->next = NULL;
    return new_node;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* l3 = createNode(0);
    struct ListNode* dummy_head = l3;
    
    int carry = 0;
    
    while (l1 || l2 || carry) {
        int val1 = l1 ? l1->val : 0;
        int val2 = l2 ? l2->val : 0;
        
        int sum = val1 + val2 + carry;
        carry = sum / 10;
        int last_digit = sum % 10;
        
        struct ListNode* new_node = createNode(last_digit);
        dummy_head->next = new_node;
        
        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
        
        dummy_head = dummy_head->next;
    }
    
    return l3->next;
}