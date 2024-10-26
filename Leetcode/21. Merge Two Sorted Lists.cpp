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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* ptr = dummyNode;

        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;

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

        while(ptr1 != NULL)
        {
            ptr->next = ptr1;
            ptr = ptr->next;
            ptr1 = ptr1->next;
        }

        while(ptr2 != NULL)
        {
            ptr->next = ptr2;
            ptr = ptr->next;
            ptr2 = ptr2->next;
        }

        return dummyNode->next;
    }
};