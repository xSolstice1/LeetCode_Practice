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
    void backtrack(TreeNode* root, vector<vector<int>>& res, vector<int>& curr, int targetSum) {
        if (!root) return;

        curr.push_back(root->val);

        if (!root->left && !root->right && root->val == targetSum) {
            res.push_back(curr);
        } else {
            backtrack(root->left,res,curr,targetSum-root->val);
            backtrack(root->right,res,curr,targetSum-root->val);
        }

        curr.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> curr;
        vector<vector<int>> res;

        backtrack(root,res,curr,targetSum);

        return res;
    }
};