/* Structure of Binary Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

//the main logic is that we are simply adding any element(to results array) that we first see, when we go to a new level

//this works because whenever we go to a new level, we check if level count is same as array length

//if the count is equal that means we havnt added any element from this level, so we add it and increase level. After increasing the level even if we come to the same lelve while backtracking
//our array count is now greater than that level so we dont add other elemets from that level



class Solution {
  public:
    void findLeftView(Node* root,vector<int>& result,int level){
        if(!root) return;
        
        if(level==result.size()){
            result.push_back(root->data);
        }
        findLeftView(root->left,result,level+1);
        findLeftView(root->right,result,level+1);
    }
    
    vector<int> leftView(Node *root) {
        // code here
        vector<int>result;
        int level=0;
        findLeftView(root,result,level);
        return result;
    }
};
