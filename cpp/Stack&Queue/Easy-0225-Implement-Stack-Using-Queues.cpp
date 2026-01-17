/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

#include <queue>

class MyStack
{
public:
	MyStack() {}

	void push(int x)
	{
		if (pushQ1)
		{
			q1.push(x);
			while (!q2.empty())
			{
				q1.push(q2.front());
				q2.pop();
			}
			pushQ1 = !pushQ1;
		}
		else
		{
			q2.push(x);
			while (!q1.empty())
			{
				q2.push(q1.front());
				q1.pop();
			}
			pushQ1 = !pushQ1;
		}
	}

	int pop()
	{
		int temp = pushQ1 ? q2.front() : q1.front();
		pushQ1 ? q2.pop() : q1.pop();
		return temp;
	}

	int top()
	{
		return pushQ1 ? q2.front() : q1.front();
	}

	bool empty()
	{
		return pushQ1 ? q2.empty() : q1.empty();
	}
private:
	std::queue<int> q1;
	std::queue<int> q2;
	bool pushQ1 = true;
};