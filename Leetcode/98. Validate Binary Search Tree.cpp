// https://leetcode.com/problems/validate-binary-search-tree/description/

// ----------------- Approach - 01 ----------------------

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MIN, LONG_MAX);
    }

    bool validate(TreeNode* node, long minimum, long maximum)
    {
        if(node == NULL)
            return true;
        
        if(node->val <= minimum || node->val >= maximum)
            return false;
        
        return validate(node->left, minimum, node->val) && validate(node->right, node->val, maximum);
    }
};


// ----------------- Approach - 02 ----------------------

class Solution {
public:

    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MIN);
    }

    bool validate(TreeNode* node, long previous)
    {
        if(node == NULL)
            return true;
        
        if(!validate(node->left, previous))
            return false;
        
        if(node->val <= previous)
            return false;
        
        return validate(node->right, node->val);
    }
};