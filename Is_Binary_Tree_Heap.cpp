/*
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
        bool isComplete(Node* tree) {
            // code here
            queue<Node*>q;
            bool isNULL=false;
            if(tree==NULL) return true;

            q.push(tree);


            while(!q.empty()){
                Node* front=q.front();
                q.pop();

                if(front->left){
                    if(isNULL==false && front->data > front->left->data){
                        q.push(front->left);
                    }
                    else{
                        return false;
                    }
                }
                else{
                    isNULL=true;
                }

                if(front->right){
                    if(isNULL==false && front->data > front->right->data){
                        q.push(front->right);

                    }
                    else{
                        return false;
                    }

                }
                else{
                    isNULL=true;
                }

            }

            return true;


        }
        
    bool isHeapProp(Node* root){
        if(!root) return true;
        
        if(root->left ==NULL && root->right==NULL) return true;
        
        bool leftAns=isHeapProp(root->left);
        bool rightAns=isHeapProp(root->right);
        
        bool currentAns=true;
        
        if(root->left && root->data < root->left->data) return false;
        
        if(root->right && root->data < root->right->data) return false;
        
        return currentAns && leftAns&& rightAns;
    }
    bool isHeap(Node* root) {
        // code here
        bool completeAns=isComplete(root);
        bool heapProperty=isHeapProp(root);
        
        return completeAns && heapProperty;
        
    }
};