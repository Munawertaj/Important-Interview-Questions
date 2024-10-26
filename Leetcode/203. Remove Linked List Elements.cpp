// https://leetcode.com/problems/remove-linked-list-elements/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode();
        ListNode *curr = dummy;

        while(head != NULL)
        {
            if(head->val != val)
            {
                curr->next = head;
                curr = head;
            }
            head = head->next;
        }

        curr->next = NULL;
        return dummy->next;
    }
};