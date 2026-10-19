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
    int findMax(TreeNode* root){
        if(!root) return -1;

        while(root->right){
            root=root->right;
        }
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;

        if(root->val==key){
            //3 cases of delete
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL; //this will set its earlier node pointing to NULL
            }
            if(root->left!=NULL && root->right==NULL){ //basically only left tree exists for this node
                //we basically need to delte this node and point the lefttree that exists below it, to a node above it.
                TreeNode* temp=root->left;
                root->left=NULL;
                delete root;
                return temp;
            }

            if(root->right!=NULL && root->left==NULL){ //basically only left tree exists for this node
                //we basically need to delte this node and point the lefttree that exists below it, to a node above it.
                TreeNode* temp=root->right;
                root->right=NULL;
                delete root;
                return temp;
            }

            if(root->right!=NULL && root->left!=NULL){
                //since this node has both left and right subtree 
                //we have two options, either replace this node's data(NOT DELTE) with max of its leftsubtree or min of right subtree
                int maxValue=findMax(root->left);
                root->val=maxValue;
                root->left= deleteNode(root->left,maxValue);
                return root;
            }

        }

        else{
            if(key<root->val){
                root->left=deleteNode(root->left,key);
            }
            else{
                root->right=deleteNode(root->right,key);
            }
        }

        return root;
    }
};