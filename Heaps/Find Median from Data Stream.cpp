#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    priority_queue<int> left_maxHeap;
    priority_queue<int, vector<int>, greater<int>> right_minHeap;
    MedianFinder() {}

    void addNum(int num) {
        if (left_maxHeap.empty() || num < left_maxHeap.top()) {
            left_maxHeap.push(num);
        } else {
            right_minHeap.push(num);
        }

        // Always have to maintain that only pne size is greater in left_maxHeap
        if (abs((int)left_maxHeap.size() - (int)right_minHeap.size()) > 1) {
            right_minHeap.push(left_maxHeap.top());
            left_maxHeap.pop();
        }else if(left_maxHeap.size() < right_minHeap.size()){
                left_maxHeap.push(right_minHeap.top());
                right_minHeap.pop();
        }
    }

    double findMedian() {
        if (left_maxHeap.size() == right_minHeap.size()) {
            return (double)(left_maxHeap.top() + right_minHeap.top()) / 2;;
        }
        return left_maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */