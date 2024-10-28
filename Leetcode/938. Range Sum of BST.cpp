// https://leetcode.com/problems/range-sum-of-bst/description/

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

// ------------ Approach - 01 ------------

class Solution {
public:
    void helper(TreeNode* root, int low, int high, int& sum)
    {
        if(!root)
            return;
        
        if(root->val >= low && root->val <= high)
            sum += root->val;
        
        helper(root->left, low, high, sum);
        helper(root->right, low, high, sum);
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        helper(root, low, high, sum);
        return sum;
    }
};

// ------------ Approach - 02 ------------

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root)
            return 0;
        
        int sum = 0;
        if(root->val >= low && root->val <= high)
            sum += root->val;
            
        if(root->val > low)
            sum += rangeSumBST(root->left, low, high);
        
        if(root->val < high)
            sum += rangeSumBST(root->right, low, high);

        return sum;
    }
};

// ------------ Approach - 03 ------------

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root)
            return 0;
            
        int left = rangeSumBST(root->left, low, high);
        int right = rangeSumBST(root->right, low, high);

        if(root->val >= low && root->val <= high)
            return root->val + left + right;

        return left + right;
    }
};