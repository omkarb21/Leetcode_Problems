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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,unsigned long long>> q;
        int maxWidth=0;
        if(root) q.push({root,1});
        while(!q.empty()){
            auto front=q.front();
            auto back=q.back();
            auto width=back.second-front.second+1;
            maxWidth=max(maxWidth,int (width));

            int size=q.size();
            for(int i=0;i<size;i++){
                auto front=q.front();
                q.pop();
                auto pIndex=front.second;
                if(front.first->left) q.push({front.first->left,2*pIndex});
                if(front.first->right) q.push({front.first->right,2*pIndex+1});

            }
        }
        return maxWidth;
    }
};