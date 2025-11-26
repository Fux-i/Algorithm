#include <unordered_map>
#include <vector>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        unordered_map<Node*, int> m{};
        vector<Node*> v{};

        int index = 0;
        auto node = head;
        while (node) {
            m.insert({node, index});
            Node* newNode = new Node(node->val);
            v.push_back(newNode);
            if (index > 0) {
                v[index - 1]->next = newNode;
            }
            index++;
            node = node->next;
        }
        // random ptr
        index = 0;
        while (head) {
            auto r = head->random;
            if (r != nullptr) {
                int i = m[r];
                v[index]->random = v[i];
            }
            index++;
            head = head->next;
        }
        return v[0];
    }
};