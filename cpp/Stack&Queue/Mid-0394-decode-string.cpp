#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    string decodeString(const string &s) {
        stack<int> numStk;
        stack<string> strStk;
        string current;
        int num = 0;

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '[') {
                // 保存当前状态，开始新的上下文
                strStk.push(current);
                numStk.push(num);
                current.clear();
                num = 0;
            } else if (c == ']') {
                // 获取重复次数和前序字符串
                int repeat = numStk.top(); numStk.pop();
                string prev = strStk.top(); strStk.pop();

                // 正确重复当前字符串
                while (repeat--) {
                    prev += current;
                }
                current = prev;
            } else {
                // 普通字符
                current += c;
            }
        }
        return current;
    }
};