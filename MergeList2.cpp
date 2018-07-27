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
        ListNode pre_head (0), *cur = &pre_head;

        while (l1 || l2)
        {
            if (l1 &&
                (!l2 || (l1->val < l2->val)))
            {
                cur->next = l1;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
            }
            
            cur = cur->next;
        }
        
        return pre_head.next;
    }
};
