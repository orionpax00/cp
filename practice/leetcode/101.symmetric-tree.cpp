/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 */

// @lc code=start
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
void dfs(TreeNode* l, vector<int>& v){
    if(l == NULL) {return;}
    dfs(l->left, v);
    v.push_back(l->val);
    dfs(l->right, v);
} 

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        vector<int> left;
        vector<int> right;
        dfs(l, left);
        dfs(r, right);
        reverse(right.begin(), right.end());
        for(int i = 0 ; i < left.size(); i++)
            if(left[i] != right[i])
                return false;

        return true; 
    }
};
// @lc code=end

