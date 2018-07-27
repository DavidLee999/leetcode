/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (nullptr == l1)
            return l2;
        if (nullptr == l2)
            return l1;
        
        ListNode *head, *tmp;
        if (l1->val > l2->val)
        {
            head = l2;
            l2 = l2->next;
        }
        else
        {
            head = l1;
            l1 = l1->next;
        }
        
        tmp = head;
        while (nullptr != l1 && nullptr != l2)
        {
            if (l1->val > l2->val)
            {
                tmp->next = l2;
                l2 = l2->next;
            }
            else
            {
                tmp->next = l1;
                l1 = l1->next;
            }
            
            tmp = tmp->next;
        }
        
        if (nullptr == l1)
            tmp->next = l2;
        else
            tmp->next = l1;
        
        return head;
    }
};
