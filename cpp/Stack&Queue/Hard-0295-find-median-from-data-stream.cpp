#include <queue>
using namespace std;

class MedianFinder {
    priority_queue<int> bigHeap{};
    priority_queue<int, vector<int>, greater<>> smallHeap{};
    int bigNum = 0;
    int smallNum = 0;

public:
    MedianFinder() {

    }

    void addNum(int num) {
        if (bigNum == 0 || bigNum != 0 && bigHeap.top() > num) {
            bigHeap.emplace(num);
            ++bigNum;
        } else {
            smallHeap.emplace(num);
            ++smallNum;
        }
        // adjust
        if (bigNum == smallNum + 2) {
            int temp = bigHeap.top(); bigHeap.pop();
            --bigNum;
            smallHeap.emplace(temp);
            ++smallNum;
        } else if (bigNum + 2 == smallNum) {
            int temp = smallHeap.top(); smallHeap.pop();
            --smallNum;
            bigHeap.emplace(temp);
            ++bigNum;
        }
    }

    double findMedian() {
        if (bigNum == smallNum) return static_cast<double>(bigHeap.top() + smallHeap.top()) / 2;
        if (bigNum < smallNum) return smallHeap.top();
        return bigHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */