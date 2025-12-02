#include <string>
using namespace std;

class Trie {
    struct Node {
        Node *children[26];
        bool is_end;
        Node() { for (int i = 0; i < 26; ++i) children[i] = nullptr; }
        Node(bool b) : is_end(b) { for (int i = 0; i < 26; ++i) children[i] = nullptr; }
    };

    Node *root;

public:
    Trie() {
        root = new Node(false);
    }

    void insert(string word) {
        Node *cur = root;
        for (auto &c: word) {
            if (!cur->children[c - 'a'])
                cur->children[c - 'a'] = new Node(false);
            cur = cur->children[c - 'a'];
        }
        cur->is_end = true;
    }

    bool search(string word) {
        Node *cur = root;
        for (auto &c: word) {
            if (!cur->children[c - 'a'])
                return false;
            cur = cur->children[c - 'a'];
        }
        return cur->is_end;
    }

    bool startsWith(string prefix) {
        Node *cur = root;
        bool res = true;
        for (auto &c: prefix) {
            if (!cur->children[c - 'a'])
                return false;
            cur = cur->children[c - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
