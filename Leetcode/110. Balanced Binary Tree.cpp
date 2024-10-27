// https://leetcode.com/problems/balanced-binary-tree/description/

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
    bool flag = true;
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true; 
        
        maxHeight(root);
        return flag;
    }

private:
    int maxHeight(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int left = maxHeight(root->left);
        int right = maxHeight(root->right);

        if(abs(left - right) > 1)
            flag = false;
        
        return 1 + max(left, right);
    }
};