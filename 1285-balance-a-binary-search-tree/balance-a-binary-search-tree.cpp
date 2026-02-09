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
    // Helper: inorder traversal to collect sorted values
    void inorder(TreeNode* root, vector<int>& vals) {
        if (!root) return;
        inorder(root->left, vals);
        vals.push_back(root->val);
        inorder(root->right, vals);
    }
    
    // Helper: build balanced BST from sorted array
    TreeNode* build(vector<int>& vals, int l, int r) {
        if (l > r) return nullptr;
        
        int m = l + (r - l) / 2;
        TreeNode* node = new TreeNode(vals[m]);
        
        node->left = build(vals, l, m - 1);
        node->right = build(vals, m + 1, r);
        
        return node;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> vals;
        
        // Step 1: Get sorted values
        inorder(root, vals);
        
        // Step 2: Build balanced BST
        return build(vals, 0, vals.size() - 1);
    }
};
