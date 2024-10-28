// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL)
            return NULL;
        
        // If both p and q are smaller than root, LCA is in the left subtree
        if (p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        
        // If both p and q are greater than root, LCA is in the right subtree
        if (p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);
        
        // If one of p or q equals root or they lie on either side of root, then root is the LCA
        return root;
    }
};