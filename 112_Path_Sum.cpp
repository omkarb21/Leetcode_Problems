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
    bool CalculatePathSum(TreeNode* root, int target, int sum){
    if(root==NULL)
    {
        return false;
    }

    if(root->left==NULL && root->right==NULL){
        sum+=root->val;
        if (sum==target){
            return true;
        }
        else{
            return false;
        }
    }
    
    sum=sum+root->val;
    bool lAns=CalculatePathSum(root->left,target,sum);
    bool rAns=CalculatePathSum(root->right,target,sum);

    return lAns || rAns;

    
}

    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        bool ans= CalculatePathSum(root, targetSum,sum);
        return ans;
    }
};