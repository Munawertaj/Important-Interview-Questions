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

// ------------------Approach - 01----------------
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        string st;
        ListNode* fast = head;
        ListNode* slow = head;
        int index = 0;
        
        while(fast != NULL && fast->next != NULL)
        {
            st.push_back(slow->val + '0');
            slow = slow->next;
            fast = fast->next->next;
            index++;
        }

        if(fast != NULL && fast->next == NULL)
            slow = slow->next;

        while(slow != NULL)
        {
            char ch = slow->val + '0';
            if(ch != st[--index])
                return false;

            slow = slow-> next;
        }

        return true;
    }
};

// ------------------Approach - 02 (Using recursion) ----------------

class Solution {
    ListNode* curr;
public:
    bool isPalindrome(ListNode* head) {
        curr = head;
        return check(head);
    }

    bool check(ListNode* ptr)
    {
        if(ptr == NULL)
            return true;
        
        bool ans = check(ptr->next) && ptr->val == curr->val;
        
        curr = curr->next;
        return ans;
    }
};