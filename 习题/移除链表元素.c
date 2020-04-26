/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode* pre = NULL;
    struct ListNode* cur = head;
 
    while(cur)//将链表遍历一遍
    {
        if(cur->val == val)
        {
            if(cur == head)//第一个节点
            {
                head = head->next;
                free(cur);
                cur = head;
            }
            else
            {
                pre->next = cur->next;
                free(cur);
                cur = pre->next;

            }
        }
        else
        {
            pre = cur;
            cur = cur->next;
        }
    }
    return head;
}
