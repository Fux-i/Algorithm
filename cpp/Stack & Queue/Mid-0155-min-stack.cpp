#include <algorithm>
#include <limits.h>
#include <stack>
#include <vector>
using namespace std;

class MinStack {
    stack<pair<int, int> > st;
public:
    MinStack() {
    }

    void push(int x) {
        if (st.size() == 0) {
            st.push({x, x});
        } else {
            st.push({x, min(x, st.top().second)});
        }
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

/*class MinStack {
    int minVal = INT_MAX;
    vector<int> v{};
public:
    MinStack() {

    }

    void push(int val) {
        v.push_back(val);
        minVal = min(minVal, val);
    }

    void pop() {
        const int back = v.back();
        v.pop_back();
        if (back == minVal) {
            int newMin = INT_MAX;
            for (int& num : v) {
                newMin = min(newMin, num);
            }
            minVal = newMin;
        }
    }

    int top() {
        return v.back();
    }

    int getMin() {
        return minVal;
    }
};*/

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
