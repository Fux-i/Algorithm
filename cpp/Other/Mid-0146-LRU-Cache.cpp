#include <unordered_map>

struct Node
{
	int   key;
	int   value;
	Node* prev;
	Node* next;

	Node(int key, int value) : key(key), value(value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
	int   capacity_;
	int   node_count_;
	Node* head_;
	Node* last_;

	std::unordered_map<int, Node*> map_;

public:
	LRUCache(int capacity) : capacity_(capacity), node_count_(0) {
		head_ = new Node(-1, -1);
		last_ = new Node(-1, -1);
		head_->next = last_;
		last_->prev = head_;
	}

	int get(int key) {
		auto it = map_.find(key);
		if (it != map_.end()) {
			Node* node = it->second;
			refresh_node(node);
			return node->value;
		}
		return -1;
	}

	void put(int key, int value) {
		auto it = map_.find(key);
		if (it != map_.end()) {
			Node* node = it->second;
			node->value = value;
			refresh_node(node);
		} else {
			if (node_count_ == capacity_) {
				remove_last();
			} else {
				node_count_++;
			}
			Node* node = new Node(key, value);
			insert_node(node, true);
		}
	}

private:
	void remove_last() {
		remove_node(last_->prev, true);
	}

	void refresh_node(Node* node) {
		remove_node(node);
		insert_node(node);
	}

	void remove_node(Node* node, bool remove_from_map = false) {
		node->next->prev = node->prev;
		node->prev->next = node->next;
		node->next = nullptr;
		node->prev = nullptr;

		if (remove_from_map)
			map_.erase(node->key);
	}

	void insert_node(Node* node, bool insert_to_map = false) {
		node->next = head_->next;
		head_->next->prev = node;
		node->prev = head_;
		head_->next = node;

		if (insert_to_map)
			map_[node->key] = node;
	}
};
