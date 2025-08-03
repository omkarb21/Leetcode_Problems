class Solution {
public:
    int getMidIndex(vector<int> inorder,int data){
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==data){
                return i;
            }
        }
        return -1;
    }
    TreeNode* constructTree(vector<int>& preorder, vector<int>& inorder,int inorderStartIndex,int inorderEndIndex, int& preIndex) {
        if(preIndex>=preorder.size()) return NULL;
        if(inorderEndIndex<inorderStartIndex) return NULL;

        cout<<"preIndex is "<<preIndex;
        int data=preorder[preIndex];
        preIndex++;
        TreeNode* root=new TreeNode(data);
        int midIndex=getMidIndex(inorder,data);
        root->left=constructTree(preorder,inorder,inorderStartIndex,midIndex-1,preIndex);
        root->right=constructTree(preorder,inorder,midIndex+1,inorderEndIndex,preIndex);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex=0;
        TreeNode* root=constructTree(preorder,inorder,0,inorder.size()-1,preIndex);
        return root;
    }
};