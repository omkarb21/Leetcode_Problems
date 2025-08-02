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
        if(root==NULL) return NULL;
        if(root==p|| root==q) return root;

        TreeNode* lNode=lowestCommonAncestor(root->left,p,q);
        TreeNode* rNode=lowestCommonAncestor(root->right,p,q);

        if(lNode==NULL && rNode!=NULL) return rNode;
        else if(lNode!=NULL && rNode==NULL) return lNode;
        else if(lNode==NULL && rNode==NULL) return NULL;
        else return root;


        
    }
};