/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Compare{
    public:
    bool operator()(ListNode* a,ListNode* b){
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*,vector<ListNode*>,Compare>pq;
        ListNode* head=NULL;
        ListNode* tail=NULL;
        //create heap of first elements of K lists
        for(int i=0;i<lists.size();i++){
            if(lists[i])
                pq.push(lists[i]);
        }
        //initialize head and tail on first min from heap
        
        if(!pq.empty()){
            ListNode* temp=pq.top();
            pq.pop();
            head=temp;
            tail=temp;

            if(temp->next){
            pq.push(temp->next);
            }   
        }
        else return NULL;

        //while Heap is not empty()
        while(!pq.empty()){
            ListNode* curr=pq.top();
            pq.pop();
            tail->next=curr;
            tail=curr;

            if(curr->next){
                pq.push(curr->next);
            }

            //if next element from same list exists, insert into hip
        //pop to get minimum , link tail to this
        }
        return head;
        
    }
};