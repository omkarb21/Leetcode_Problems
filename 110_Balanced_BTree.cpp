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
    int getHeight(TreeNode* root){
        if(root==NULL){
            return 0;
        }

        int count=1;
        int lheight=getHeight(root->left);
        int rheight=getHeight(root->right);
        return max(lheight,rheight)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL || (root->left==NULL && root->right==NULL))
        return true;
    
    int lheight=getHeight(root->left);
    int rheight=getHeight(root->right);

    if(abs(lheight-rheight)>1){
        
        return false;
    }

    bool leftAns=isBalanced(root->left);
    if(leftAns==false) return false;
    bool rightAns=isBalanced(root->right);
    if(rightAns==false) return false;
    return true;
    }
};