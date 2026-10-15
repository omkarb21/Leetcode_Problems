//---Q2: TOp view of Binary Tree

//here we travel level wise. we store the node and a marker that indicates what level is this node from
//this marker woudl help us tell whether or not this is a leftmost node/rightmost node
//we keep on storing leftmost and rightmost nodes to a map with 'marker' as key and node as its value
//so at the end you will have map which looks like 
// {

//     -2:LeftmostNode2
//     -1:leftmostnode1
//     0:root
//     1:rightmostNode1
//     2:rightmostNode2

// }

//how marking logic works
//for marker logic we could have simply stored level number but we need to identify the leftmost and the rightmost node of the same level
//just storign level number will have 'level number' same for all the nodes and we cant tell is this leftmost node or rightmost node
//so for marker we use following scheem : goign left (do -1 from earlier node marker), goign right(do +1 to earlier node marker)


/* 
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
}; */

class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        vector<int>result;
        
        unordered_map<int,Node*>distMap;
        queue<pair<Node*, int>>q;
        
        int minDist=INT_MAX;
        int maxDist=INT_MIN;
        
        int dist=0;
        
        //add all nodes and markers to a queue
        //simulataneously add nodes to map
        if(root){
            q.push({root,dist});
            distMap[dist]=root;
        }
        else return result;
        
        while(!q.empty()){
            pair<Node*,int>front=q.front();
            q.pop();
            
            Node* outNode=front.first;
            dist=front.second;
            
            maxDist=max(dist,maxDist);
            minDist=min(dist,minDist);
            
            if(outNode->left){
                q.push({outNode->left,dist-1});
                if(distMap.find(dist-1)==distMap.end()){
                    distMap[dist-1]=outNode->left;
                }
            }
            if(outNode->right){
                q.push({outNode->right,dist+1});
                if(distMap.find(dist+1)==distMap.end()){
                    distMap[dist+1]=outNode->right;
                }
            }
        }
        
        //iterate teh map to get the answer        
        for(int i=minDist;i<=maxDist;i++){
            int val=distMap[i]->data;
            result.push_back(val);
        }
        
        return result;
        
        
    }
};