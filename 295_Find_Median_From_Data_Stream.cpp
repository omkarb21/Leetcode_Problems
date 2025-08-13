class MedianFinder {
public:
    priority_queue<int>maxHeap;
    priority_queue<int,vector<int>,greater<int>>minHeap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.size()==minHeap.size()){
            double median=findMedian();
            if(num>median){
                minHeap.push(num);
            }
            else{
                maxHeap.push(num);

            }
        }
        else if(maxHeap.size()==minHeap.size()+1){
            double median=findMedian();
            if(num>median){
                minHeap.push(num);
            }
            else{
                int topElement=maxHeap.top();
                maxHeap.pop();
                minHeap.push(topElement);
                maxHeap.push(num);
            }
        }
        else{
            double median=findMedian();
            if(num>median){
                int topElement=minHeap.top();
                minHeap.pop();
                maxHeap.push(topElement);
                minHeap.push(num);
            }
            else{
                maxHeap.push(num);
            }
        }
    }
    
    double findMedian() {
        if(minHeap.size()==0 && maxHeap.size()==0){
            return 0;
        }
        else if(maxHeap.size()==minHeap.size()){
            double maxi=maxHeap.top()*1.0;
            double mini=minHeap.top()*1.0;
            return (maxi+mini)/2;
        }
        else if(maxHeap.size()==minHeap.size()+1){
            double ans=maxHeap.top();
            return ans;
        }
        else{
            double ans=minHeap.top();
            return ans;
        }
    }
};