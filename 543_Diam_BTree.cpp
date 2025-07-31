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
    int MaxHeight=0;
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);  
        return MaxHeight - 1;  //reducing one because we are counting edges instead of nodes
    }
    int dfs(TreeNode* root) {
        if(root==NULL)return 0;

        int CurrentNodeCount=1;
        int lheight=dfs(root->left);
        int rheight=dfs(root->right);

        int totalHeight=lheight+rheight+CurrentNodeCount;

        if(totalHeight>MaxHeight) MaxHeight=totalHeight;

        return max(lheight+1,rheight+1);

    }
};