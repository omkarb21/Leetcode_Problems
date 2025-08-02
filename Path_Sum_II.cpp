class Solution {
public:
void CalPathSum(TreeNode* root, int target, int sum, vector<int>temp, vector<vector<int>> & ans){
    if(root==NULL)
    {
        return;
    }

    if(root->left==NULL && root->right==NULL){
        sum+=root->val;
        if (sum==target){
            temp.push_back(root->val);
            ans.push_back(temp);
            return;
        }
        else{
            return;
        }
    }
    temp.push_back(root->val);
    sum=sum+root->val;
    CalPathSum(root->left,target,sum,temp,ans);
    CalPathSum(root->right,target,sum,temp,ans);
    return;
    
}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum=0;
        vector<int> temp;
        vector<vector<int>>ans;
        CalPathSum(root,targetSum,sum,temp,ans);
        return ans;
    }
};