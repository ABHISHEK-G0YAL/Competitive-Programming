// https://leetcode.com/problems/find-median-from-data-stream/

class MedianFinder {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    void addNum(int num) {
        if (!minHeap.empty() && num < minHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        if (minHeap.size() > maxHeap.size() + 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        } else if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    double findMedian() {
        if (minHeap.size() == maxHeap.size()) {
            return ((double)minHeap.top() + maxHeap.top()) / 2;
        } else if (minHeap.size() > maxHeap.size()){
            return minHeap.top();
        } else {
            return maxHeap.top();
        }
    }
};