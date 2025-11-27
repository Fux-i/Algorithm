#include <array>
#include <bitset>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head) return head;

        array<int, 200001> arr{};
        ListNode* node = head;
        while (node) {
            arr[node->val + 100000]++;
            node = node->next;
        }
        node = head;
        for (int i = 0; i < 200001; i++) {
            while (arr[i]--) {
                node->val = i - 100000;
                node = node->next;
            }
        }
        return head;
    }
};