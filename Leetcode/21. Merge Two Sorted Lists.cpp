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
    ListNode* mergeTwoLists(ListNode* ptr1, ListNode* ptr2) {
        ListNode* dummyNode = new ListNode();
        ListNode* ptr = dummyNode;

        while(ptr1 != NULL && ptr2 != NULL)
        {
            if(ptr1->val < ptr2->val)
            {
                ptr->next = ptr1;
                ptr1 = ptr1->next;
            }
            else
            {
                ptr->next = ptr2;
                ptr2 = ptr2->next;
            }

            ptr = ptr->next;
        }

        ptr->next = ptr1 ? ptr1 : ptr2;

        return dummyNode->next;
    }
};