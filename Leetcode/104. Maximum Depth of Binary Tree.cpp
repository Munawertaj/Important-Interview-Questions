// https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

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

// ---------------- Approach - 1 ---------------------

class Solution {
public:
    int maxCount = 0;
    
    int maxDepth(TreeNode* root) {
        traverse(root, 0);
        return maxCount;
    }

    void traverse(TreeNode* root, int count)
    {
        if(root == NULL)
        {
            maxCount = max(maxCount, count);
            return;
        }
        
        traverse(root->left, count + 1);
        traverse(root->right, count + 1);
    }

};


// ---------------- Approach - 2 ---------------------

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};