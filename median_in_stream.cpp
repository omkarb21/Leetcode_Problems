class MedianFinder {
public:
    priority_queue<int,vector<int>,greater<int>>minHeap;
    priority_queue<int>maxHeap;
    float median;
    int maxHeapSize;
    int minHeapSize;
    MedianFinder() {
        maxHeapSize=0;
        minHeapSize=0;
        median=0;
    }
    
    void addNum(int num) {
        
        if(num>median){
            if(maxHeapSize==minHeapSize){
                minHeap.push(num);
                median=minHeap.top();
                minHeapSize++;
            }
            else if(maxHeapSize+1==minHeapSize){
                int temp=minHeap.top();
                minHeap.pop();
                maxHeap.push(temp);
                maxHeapSize++;
                minHeap.push(num);
                median=(minHeap.top()+maxHeap.top())/2.0;
                
            }
            else{
                minHeap.push(num);
                median=(minHeap.top()+maxHeap.top())/2.0;
                minHeapSize++;
            }
        }
        else{
            if(maxHeapSize==minHeapSize){
                maxHeap.push(num);
                median=maxHeap.top();
                maxHeapSize++;
            }
            else if(maxHeapSize+1==minHeapSize){
                maxHeap.push(num);

                median=(maxHeap.top()+minHeap.top())/2.0;
                maxHeapSize++;


                
            }
            else{
                int temp=maxHeap.top();
                maxHeap.pop();
                minHeap.push(temp);
                minHeapSize++;
                maxHeap.push(num);
                median=(maxHeap.top()+minHeap.top())/2.0;
            }
        }
    }
    
    double findMedian() {
        return median;
    }
};
