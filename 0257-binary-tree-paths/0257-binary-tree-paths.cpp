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
    void backtrack(TreeNode* root, vector<string>& res, string curr) {
        if (root == NULL) {
            return;
        }

        if (!curr.empty()) {
            curr += "->";
        }
        curr += to_string(root->val);

        if (root->left == NULL && root->right == NULL) {
            res.push_back(curr);
            return;
        }

        if (root->left) {
            backtrack(root->left, res, curr);
        }
        if (root->right) {
            backtrack(root->right, res, curr);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        backtrack(root,res,"");
        return res;
    }
};