/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* cur = head;
    struct ListNode*  pre = NULL;
    struct ListNode*  Next = NULL;

    while(cur)
    {
        //Äæ×ª
        Next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = Next;

    }
    
    return pre;   
    
    
}
