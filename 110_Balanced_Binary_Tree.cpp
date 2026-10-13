//find if binary tree balanced or not

//a balanced tree has, at evey node depth on its left-right<=1

class Solution {
public:
    int checkBalanced(TreeNode* root, bool& ans){
        if(root==NULL){
            return 0;
        }

        int leftAns=checkBalanced(root->left,ans);
        int rightAns=checkBalanced(root->right,ans);

        if(abs(leftAns-rightAns)>1){
            ans=false;
        }
        int maxAns=max(leftAns,rightAns);
        return 1+maxAns;
    }
    bool isBalanced(TreeNode* root) {
        bool ans=true;
        checkBalanced(root,ans);
        return ans;
    }
};